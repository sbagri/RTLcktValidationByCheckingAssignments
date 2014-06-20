#------------------------------------------------------------------------------
# pycparser: c-to-c.py
#
# Example of using pycparser.c_generator, serving as a simplistic translator
# from C to AST and back to C.
#
# Copyright (C) 2008-2012, Eli Bendersky
# License: BSD
#------------------------------------------------------------------------------
from __future__ import print_function
import sys

# This is not required if you've installed pycparser into
# your site-packages/ with setup.py
#
sys.path.extend(['.', '..'])

from pycparser import parse_file, c_parser, c_generator


def translate_to_c(filename):
	print("Hi")
	ast = parse_file(filename, use_cpp=False)
	generator = c_generator.CGenerator()
	text2 = "";
	text2 = generator.visit(ast);
#	re.compile("if")
	text = text2.splitlines()
	for line in text:
		if line.strip().startswith("if"):
			print(line[5:])
	print()


def zz_test_translate():
    # internal use
    src = r'''
    
    void f(char * restrict joe){}
    
int main(void)
{
    unsigned int long k = 4;
    int p = - - k;
    return 0;
}
'''
    parser = c_parser.CParser()
    ast = parser.parse(src)
    ast.show()
    generator = c_generator.CGenerator()
    
    print(generator.visit(ast))
    
    # tracing the generator for debugging
    #~ import trace
    #~ tr = trace.Trace(countcallers=1)
    #~ tr.runfunc(generator.visit, ast)
    #~ tr.results().write_results()


#------------------------------------------------------------------------------
if __name__ == "__main__":
    #zz_test_translate()
    if len(sys.argv) > 1:
        translate_to_c(sys.argv[1])
    else:
        print("Please provide a filename as argument")

