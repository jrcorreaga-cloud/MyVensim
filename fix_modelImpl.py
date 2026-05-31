import re

with open('src/modelImpl.cpp', 'r') as f:
    text = f.read()

text = re.sub(
    r'// Destructor\s*ModelImpl::~ModelImpl\(\) \{\s*// Architectural Note:.*?\s*\*\s*destroying System and Flow instances.*?\s*\*/',
    '''// Destructor\nModelImpl::~ModelImpl() {\n    /** \n     * Architectural Note: Following aggregation semantics, the Model refrains from\n     * destroying System and Flow instances directly. Responsibility lies with the client.\n     */''',
    text, flags=re.MULTILINE | re.DOTALL
)

with open('src/modelImpl.cpp', 'w') as f:
    f.write(text)

print("done")
