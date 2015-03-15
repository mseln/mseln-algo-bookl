import os, shlex, subprocess 

def traverse(path):
    with open(path,'r') as f:
        fcont = f.readline()
        
        meta = {}
        usrdepend = []
        sysdepend = []
        tmp_path = ''

        # read all meta
        while(fcont[0:2] == '//'):
            info = fcont.split(' ', 2)
            metakey = info[1].strip()
            metaval = info[2].strip()
            meta[metakey] = metaval
            fcont = f.readline()

        # read dependencies (include)
        while(fcont[0:8] == '#include' or fcont in ['\n', '\r\n']):
            if(fcont in ['\n', '\r\n']):
                fcont = f.readline()
                continue
            info = fcont.split(' ', 1);
            if(info[1][0] == '<'):
                sysdepend += [info[1][1:-2]]
            if(info[1][0] == '"'):
                usrdepend += [info[1][1:-2]]
            fcont = f.readline()

        # get file name and parent folder, save rest of file temporary for
        # latex.
        fname = os.path.split(path)[1]
        dname = os.path.split(os.path.split(path)[0])[1]
        if not os.path.exists('tmp/' + dname):
            os.makedirs('tmp/' + dname)
        with open('tmp/' + dname + '/' + fname,'w') as tmp:
            tmp.write(fcont + f.read())

        tmp_path = 'tmp/' + dname + '/' + fname

    traversed = { 'meta': meta, 
                  'sysdepend': sysdepend,
                  'usrdepend': usrdepend, 
                  'tmp_path': tmp_path,
                }

    return traversed

def texify(traversed):
    textified = ''

    # add meta info to tex file
    meta_keys = ['File:', 'Author:', 'Updated:', 'Description:', 
                 'Input:', 'Output:']
    for key in meta_keys:
        try:
            textified += key + ' '+ traversed['meta'][key].replace('_','\_') + '\\newline \n'
            del traversed['meta'][key]
        except:
            pass

    # add dependencies to tex file
    dependencies = ['sysdepend','usrdepend']
    for dep in dependencies:
        first = True
        textified += 'Import: '
        for dep in traversed[dep]:
            if(first):
                textified += dep.replace('_','\_')
                first = False
            else:   
                textified += ', ' + dep.replace('_','\_')
        if not first: textified += '.'
        textified += '\\newline \n'

    textified += '\lstinputlisting{' + traversed['tmp_path'] + '}'

    return textified

if not os.path.exists('tmp'):
    os.makedirs('tmp')

content = ''
with open('tcr_header.tex','r') as f:
    content += f.read()

exclude = set(['tcr'])
for root, dirs, files in os.walk('..', topdown=True):
    dirs[:] = [d for d in dirs if d not in exclude]
    for name in files:
        t = traverse(os.path.join(root, name))
        content += texify(t)   

with open('tcr_footer.tex','r') as f:
    content += f.read()

with open('tcr.tex','w') as f:
    f.write(content)

proc=subprocess.Popen(shlex.split('pdflatex tcr.tex'))
proc.communicate()

# os.unlink('tcr.log')
# os.unlink('tcr.aux')
