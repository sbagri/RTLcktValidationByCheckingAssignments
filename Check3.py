#!/usr/bin/python33
# Author: Sharad Bagri
# Copyright 2013 Sharad Bagri - The dude

# requires properly indented cpp and h file, two or more bracksets 
#i.e { or } shouldn't be in same line
# finding conditions may not work then, others should work fine
# if, else, else if conditions should be just above {

import re
from z3 import BitVec, Solver, unsat, sat, Not, ULT, ULE, UGT, UGE, Or #@UnresolvedImport
#from z3 import *
from pycparser import c_generator #@UnresolvedImport
from pycparser.c_parser import CParser #@UnresolvedImport
#from ast import *



def main():
    cppfile = 'Vtop_b12.cpp'
    hfile = 'Vtop_b12.h'
    CoveragesToTest = range(104 + 1)
    
    cppstring=[]
    hstring=[]
    check = check_mod()
    check.readfi(cppfile, cppstring)
    check.readfi(hfile, hstring)
    seqfunc=[]
    check.get_seqfunc(cppstring, seqfunc)
    AllSigList = check.get_all_sig_names(hstring, seqfunc)
    parser = CParser()
    generator = c_generator.CGenerator()

#    cov_no = 1
    for cov_no in CoveragesToTest:
        #cov_no = 3
        #Making global instance of CParser and CCgenerator
        #as their they take a long time to run. So, just making it once

        print("\n\nCoverage No. to test : {}".format(cov_no))
        
        trueCond, falseCond = check.getAllCondsForCovNo(seqfunc, cov_no)

        # Most probably this full search can be simplified to getting first false or true condition after detecting it
        CondType, CondNo = check.CondAboveCovNo(seqfunc, cov_no, trueCond, falseCond)
        SigOnDecision = []
        if CondType == "falseCond":
            SigOnDecision = check.getSigFromCond(falseCond[CondNo], AllSigList)
            print("Coverage {} requires {} to be false".format(cov_no, falseCond[CondNo]))
        else:
            SigOnDecision = check.getSigFromCond(trueCond[CondNo], AllSigList)
            print("Coverage {} requires {} to be true".format(cov_no, trueCond[CondNo]))
        print("It involves Signal : {}".format(SigOnDecision))
    
        SigAssignDict1 = check.GetAllAssignOfSig(SigOnDecision, seqfunc)
        SigAssgnStrip1 = check.StripSign(SigAssignDict1)
        NewSig1 = check.findNewSig(SigAssgnStrip1, SigOnDecision, AllSigList)
        
        print("Which is assigned values at {}".format(SigAssgnStrip1))

        SigAssignDict2 = check.GetAllAssignOfSig(NewSig1, seqfunc)
        SigAssgnStrip2 = check.StripSign(SigAssignDict2)
        if len(NewSig1)>0:
            print("This involves New Signals = {}".format(NewSig1))
            print("Which is assigned values at {}".format(SigAssgnStrip2))
        if len(SigAssgnStrip2)>0:
            NewSig2 = []
            SigOnDecision += NewSig1
            NewSig2 = check.findNewSig(SigAssgnStrip2, SigOnDecision, AllSigList)
            if len(NewSig2)>0:
                print("This involves New Signals = {}".format(NewSig2))
                SigOnDecision += NewSig2
                NewSig3 = "Going 3 levels deep hasn't been implemented, Visit later :)"
                print(NewSig3)
    
        print("Final list of signals on which coverage {} depends {}\n".format(cov_no, SigOnDecision))

        # Done getting all signals till here.
        #z3 signals initialization code
        z3Sigs = []
        flag = 0
        for Sigs in SigOnDecision:
            if type(AllSigList[Sigs]) == int:
                msb = AllSigList[Sigs]
                z3Sigs.append(BitVec('{}'.format(Sigs), msb))
    #            print("{} = BitVec(\'{}\', {})".format(Sigs, Sigs, msb))
            else:
                print("""Error: Probably an array, whose definition for z3 hasn't 
    				been written\n\n""")
                flag = 1
                break
        if flag == 1: continue
        print("All constraints on final signals are")
        s = Solver()
        for idx, cond in enumerate(trueCond):
            cond = cond.strip().replace(('vlTOPp->'), '').replace('(IData)','')
            for Sig in SigOnDecision:
                if re.search(r"\b{}\b".format(Sig), cond) is not None:
                    print("{} should be true".format(trueCond[idx]))
                    clause1 = check.GetZ3String(1, trueCond[idx], SigOnDecision, z3Sigs, parser, generator, AllSigList)
                    if clause1 != "":
                        clauseeval = eval(clause1)
                        s.add(clauseeval)
                    break

        for idx, cond in enumerate(falseCond):
            cond = cond.strip().replace(('vlTOPp->'), '').replace('(IData)','')
            for Sig in SigOnDecision:
                if re.search(r"\b{}\b".format(Sig), cond) is not None:
                    #if any new signal is found then don't take this cond
                    print("{} should be false".format(falseCond[idx]))
                    clause1 = check.GetZ3String(0, falseCond[idx], SigOnDecision, z3Sigs, parser, generator, AllSigList)
                    if clause1 != "":
                        clauseeval = eval(clause1)
                        s.add(clauseeval)
                    break
    
        #need to put main condition first
        print("Assignments 1 level deep and their coverage no. are {}".format(SigAssgnStrip1))
        print("Assignments 2 level deep and their coverage no. are {}".format(SigAssgnStrip2))
        satis = []
        unsatis = []
        for Sig1 in SigAssgnStrip1:
            Sig1cl = check.GetZ3String(1, Sig1.replace(';',''), SigOnDecision, z3Sigs, parser, generator, AllSigList)
            if Sig1cl != "":
                Sig1s = eval(Sig1cl)
                s.push()
                s.add(Sig1s)
                Cover_No = int(SigAssgnStrip1[Sig1])
                if s.check() == sat:
                    if Cover_No not in satis: satis.append(Cover_No)
                else:
                    if Cover_No not in unsatis: unsatis.append(Cover_No)
            
            for Sig2 in SigAssgnStrip2:
                sig2ss = check.GetZ3String(1, Sig2.replace(';',''), SigOnDecision, z3Sigs, parser, generator, AllSigList)
                if sig2ss != "":
                    sig2s = eval(sig2ss)
                    s.push()
                    s.add(sig2s)
                    #            print s.check()
                Cover_No = int(SigAssgnStrip1[Sig1])
                if s.check() == sat:
                    if Cover_No not in satis: satis.append(Cover_No)
                else:
                    if Cover_No not in unsatis: unsatis.append(Cover_No)
                    s.pop()
            
            if Sig1cl != "":
                s.pop()



        print("Satisfiable Coverages are {}".format(satis))
        print("Unsatisfiable Coverages are {}".format(unsatis))
        if ((len(satis) == 0) and (len(unsatis) == 0)):
            print("Looks like 'Input' so can be assigned any value")
    


class check_mod():
    def __init__(self):
        pass

    def readfi(self, filename, string):
        """ Read 'filename' and returns list with each line as element of that list"""
        self.fhand = open(filename, 'r')
        for line in self.fhand:
            string.append(line)
            
    def get_all_sig_names(self, Hstring, seqfunc):
        """returns all global, local and input signal names as dictionary
        from h file and _sequent__TOP__1 function. Syntax of each dictionary entry is
        <Signal Name>:<No. of bits for the signal>,
        <(optional) maximum array index of signal (if present)>
        
        """
        ln_no = 0
        sig_arr = {}
        regex1 = re.compile('^\s+VL_(IN|SIG)(\d+)*\((.+),(\d+),...+')
        regex2 = re.compile('(...+)\[(\d+)\]')
        #search for signals and inputs listed between PORTS and symbol table
        while Hstring[ln_no].find("PORTS") < 0:
            ln_no+=1
        while Hstring[ln_no].find("Symbol table") < 0:
            res1 = regex1.search(Hstring[ln_no])
            if res1:
                signame = res1.group(3)
                msb = int(res1.group(4))
                #splitting the array index part, if it exists
                if signame.find('[') > -1:
                    res2 = regex2.search(signame)
                    if res2:
                        signame = res2.group(1)
                        arrayindex = int(res2.group(2))
                        sig_arr[signame] = [msb + 1, arrayindex]
                    else:
                        print("Can't find the array index for {}".format(signame))
                else:
                    sig_arr[signame] = msb + 1
            ln_no += 1
        
        #now looking SeqFunc, some ckt like b07 have signals there  
        ln_no = 0
        while seqfunc[ln_no].find("Body") < 0:
            res1 = regex1.search(seqfunc[ln_no])
            if res1:
                signame = res1.group(3)
                msb = int(res1.group(4))
                #splitting the array index part, if it exists
                if signame.find('[') > -1:
                    res2 = regex2.search(signame)
                    if res2:
                        signame = res2.group(1)
                        arrayindex = int(res2.group(2))
                        sig_arr[signame] = [msb + 1, arrayindex]
                    else:
                        print("Can't find the array index for {}".format(signame))
                else:
                    sig_arr[signame] = msb + 1
            ln_no += 1

        return sig_arr


    def get_seqfunc(self, instring, outstring):
        """ from cpp file get contents of full
        void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) function
        as a list where each line of function is an element of that list
        """
        ln_no = 0
        
        while (instring[ln_no].strip() != "void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp)"):
            ln_no += 1
        ln_no += 1
        num_brac = 0
        
        while (instring[ln_no].find('{') < 0):
            ln_no += 1;
        num_brac += instring[ln_no].count('{')
        outstring.append(instring[ln_no])
        ln_no += 1;
                
        while num_brac > 0:
            outstring.append(instring[ln_no])
            num_brac += instring[ln_no].count('{')
            num_brac -= instring[ln_no].count('}')
            ln_no +=1
    
    def getAllCondsForCovNo(self, SeqFBuf, Cov):
        """Takes coverage no and _sequent__TOP__1 function contents as inputs
        and returns true and false conditions to reach that coverage no. as
        elements of a list
        conditions aren't striped of any extraneous information, so that line
        can be searched again if needed
        """
        #first reach the coverage no
        ln_no = 0
        Tcond = []
        Fcond = []
        while(SeqFBuf[ln_no].strip().find('__Vcoverage[{}]'.format(Cov)) < 0):
            ln_no += 1
        
        num_brac = 0
        
        #come up till beginning of seq_func and see conditions in all active code blocks
        while ln_no > -1:
            if(SeqFBuf[ln_no].find('}') > -1):
                num_brac += 1
            
            elif ((SeqFBuf[ln_no].find('{')) > -1):
                if num_brac == 0:
                    ln_no -= 1
                    if ln_no < 0: break
                    condline = SeqFBuf[ln_no].strip()
                    regex1 = re.compile('.+?\((.*)\)')
                    if (((condline.find("else if")) > -1) | ((condline.find("if")) > -1)):
                        res1 = regex1.search(condline)
                        Tcond.append(res1.group(1))
                    
                    elif ((condline.find("else")) > -1):
                        ln_no -= 1
                        num_brckt = 0
                        exit_cond = True
                        while (exit_cond):
                            num_brckt -= SeqFBuf[ln_no].count('}')
                            num_brckt += SeqFBuf[ln_no].count('{')
                            ln_no -= 1
                            while ((num_brckt == 0) and exit_cond):
                                condiline = SeqFBuf[ln_no].strip()
                                if (((condiline.find("else if")) > -1) | \
                                    ((condiline.find("if")) > -1)):
                                    res2 = regex1.search(condiline)
                                    Fcond.append(res2.group(1))
                                exit_cond = not(SeqFBuf[ln_no].find('if') > -1) & \
                                (SeqFBuf[ln_no].find('else if') < 0)
                            
                    else: print("some condition other than if, else if, else at line no {} \
                                + where sequent function starts".format(ln_no))    
                else:
                    num_brac -= 1
            
            ln_no -= 1
            
        return Tcond, Fcond
        
      
    def CondAboveCovNo(self, SeqFBuf, cover_no, trueCond, falseCond):
        """
        Gets the last condition in order reach a particular coverage.
        Also whether that condition should be true or false
        returns in format "trueCond"/"falseCond", Condition No. of either list
        """
        ln_no = 0
        while(SeqFBuf[ln_no].find('__Vcoverage[{}]'.format(cover_no)) < 0):
            ln_no += 1
                
        while(SeqFBuf[ln_no].find('{') < 0):
            ln_no -= 1
        ln_no -= 1 # should have if or else or else-if condition here
        
        
        regexif = re.compile('^\s*if\s*\((.*)\)\s*$')
        #regexelseif = re.compile('^\s*else if\s*\(')
        regexelse = re.compile('^\s*else\s*$')
        
        resif = regexif.search(SeqFBuf[ln_no])
        if resif:
            for i in range(len(trueCond)):
                if trueCond[i].find(resif.group(1)) > -1:
                    return "trueCond", i
            print("couldn't find any true condition matching {}".format(resif.group(1)))

        else:
            reselse = regexelse.search(SeqFBuf[ln_no])
            if reselse:
                num_brak = 0
                ln_no -= 1
                exit_cndn = False
                while(not exit_cndn):
                    num_brak -= SeqFBuf[ln_no].count('}')
                    num_brak += SeqFBuf[ln_no].count('{')
                    if num_brak == 0:
                        resels = regexif.search(SeqFBuf[ln_no])  
                        if(resels):
                            for i in range(len(falseCond)):
                                if falseCond[i].find(resels.group(1)) > -1:
                                    return "falseCond", i
                            print("couldn't find any false condition matching {}".format(reselse.group(1)))
                    ln_no -= 1
                
                
            else:
                print("some condition other than if and else at line {} + sequent top func".format(ln_no))

    def getSigFromCond(self, Condn, SigDict):
        """Extract signals from given conditions.
        It looks on elements of signal dictionary and returns list
        of all signals present in the condition 
        
        """
        RetList = []
        for Sig in SigDict:
            Sig = Sig.strip().replace(('vlTOPp->'),'').replace('(IData)','')
            rgx1 = re.compile(r"\b{}\b".format(Sig))
            res1 = rgx1.search(Condn)
            if res1:
                RetList.append(Sig)
        return RetList
    
    def GetAllAssignOfSig(self, SigNames, SeqFncBuf):
        """return Dictionary with each key as line where each signal in SigNames
        is assigned value and value of that key is the coverage no. for that.
        No coverage no. means its in the outermost bracket of function and is
        most probably local variable.
        Takes care if signal is type casted or not
        """
        LineDict = {}
        rgx_cov = re.compile("__Vcoverage\[(\d+)\]")
        for Sig in SigNames:
            rgx1 = re.compile(r"\b{}\W*[^!]=".format(Sig))
            for ln_no, line in enumerate(SeqFncBuf):
                res1 = rgx1.search(line)
                if res1:
                    LineDict[line.strip()] = -1
                    ln_no_assign = ln_no
                    num_brak = 0
                    #going upwards and search for coverage no.
                    while(num_brak < 1):
                        CurrLine = SeqFncBuf[ln_no]
                        num_brak -= CurrLine.count('}')
                        num_brak += CurrLine.count('{')
                        if num_brak == 0:
                            res1 = rgx_cov.search(CurrLine)
                            if res1:
                                LineDict[line.strip()] = int(res1.group(1))
                                break
                        ln_no -= 1
                    
                    else:
                        ln_no = ln_no_assign + 1 # +1 here because the same
                        #line has been analyzed previously
                        maxlines = len(SeqFncBuf)
                        while(num_brak > 0):
                            CurrLine = SeqFncBuf[ln_no]
                            num_brak -= CurrLine.count('}')
                            num_brak += CurrLine.count('{')
                            if num_brak == 1:
                                res2 = rgx_cov.search(CurrLine)
                                if res2:
                                    LineDict[line.strip()] = int(res2.group(1))
                                    break
                            ln_no += 1
                            if ln_no >= maxlines :
                                break
                            
        return LineDict
    
    def findNewSig(self, SigAssignDict, SigAlreadyChecked, AllSigList):
        """get all instances of assignment to a particular signal.
        if any of those assignments involve some signal which hasn't been
        encountered before then add it to SigCalled and return it.
        Used to know if some new signal also needs to be considered while
        going in previous time frame 
        """
        SigCalled = []
        SigRemaining = AllSigList.copy()
        for Sig in SigAlreadyChecked:
            del SigRemaining[Sig]
            

        for SigAsign in SigAssignDict:
            SigAsign.strip().replace(('vlTOPp->'), '').replace('(IData)','')
            for Sig in SigRemaining:
                regx1 = re.compile("\W{}\W".format(Sig))
                res1 = regx1.search(SigAsign)
                if res1:
                    SigCalled.append(Sig)
        
        return SigCalled
    
    def StripSign(self, SigDict):
        """Strips extra information from keys of dictionary.
        Extra info are ('vlTOPp->'), (IData)
        """
        RetSigDict = {}
        for SigAsign in SigDict:
            RetSigDict[SigAsign.strip().replace(('vlTOPp->'), '').\
                       replace('(IData)','')] = SigDict[SigAsign]
        return RetSigDict
            
    def GetZ3String(self, TorF, exprsn, SigList, z3Sigs, parser, generator, AllSigList):
        """Takes an 'exprsn' in string format and returns z3 equivalent of it
        so that it can be fed to s.add in terms of variables created for z3
        """
        CondStr = ""
        exprsn = exprsn.strip().replace(('vlTOPp->'), '').replace('(IData)','')
        CondStr = ""
        FullMain = self.GetMain(TorF, exprsn, SigList, AllSigList)
        ast =  parser.parse(FullMain)
        text2 = generator.visit(ast)
        text = text2.splitlines()
        for line in text:
            if line.strip().startswith("if"):
                CondStr = (line.split('if', 1))[1]
                break
        
        for idx, sigs in enumerate(SigList):
            #CondStr = re.sub(r"([\s{0}]+)({1})([\s{2}]+)".format(punc,sigs,punc) ,r"\1z3Sigs[{}]\3".format(idx), CondStr)
            CondStr = re.sub(r"\b{}\b".format(sigs), r"z3Sigs[{}]".format(idx), CondStr)
        
#        print CondStr
#        regx1b = re.compile('^\s*\((.*)\)$')      
#        res1 = regx1b.search(CondStr)
#        if res1:
#            CondStr = res1.group(1)
        return CondStr

    
    def GetMain(self, TorF, Expn, SigList, AllSigList):
        """Takes a true of false condition and makes a C program with it
		It adds void main() and adds the condition into an if block.
		This is needed so that the parser can parse the condition,
		without a main it doesn't parse the condition
		"""
        Sigs = self.getSigFromCond(Expn, SigList)
        #print Sigs
        if TorF:
            if (re.search("(>=|>|<=|<|==|!=)", Expn)):
                if len(Sigs) > 1:
                    if(AllSigList[Sigs[0]] != AllSigList[Sigs[1]]):
                        print("Error: BitVectors of different length, Can't handle now")
                        pseudoc = r"""void main()
                        {
                        }
                        """
                        return pseudoc
                    
                pseudoc = r"""void main()
                {
                if("""
                pseudoc += Expn
                pseudoc += r""")
                ;
                }
                """                
            elif ((Expn.find("=") > -1) and (Expn.find("==") < 0)):
                if len(Sigs) > 1:
                    if(AllSigList[Sigs[0]] != AllSigList[Sigs[1]]):
                        print("Error: BitVectors of different length, Can't handle now")
                        pseudoc = r"""void main()
                        {
                        }
                        """
                        return pseudoc

                Expn = re.sub(r"=", r"==", Expn)
                pseudoc = r"""void main()
                {
                if("""
                pseudoc += Expn
                pseudoc += r""")
                ;
                }
                """
            elif (Expn.find("|") > -1):
                print("Right Now difference between logical Or and Bitwise Or is not implemented")
                pseudoc = r"""void main()
                {
                }
                """
               
            else:
                pseudoc = r"""void main()
                {
                if(("""
                pseudoc += Expn
                pseudoc += r""") != 0)
                ;
                }
                """

        else:
            if Expn.find("==") > -1:
                Expn = Expn.replace("==", "!=")
                pseudoc = r"""void main()
                {
                if("""
                pseudoc += Expn
                pseudoc += r""")
                ;
                }
                """
               
            elif Expn.find("!=") > -1:
                Expn = Expn.replace("!=", "==")
                pseudoc = r"""void main()
                {
                if("""
                pseudoc += Expn
                pseudoc += r""")
                ;
                }
                """
            elif ((Expn.find(">") > -1) and (Expn.find(">>") < 0)):
                Expn = Expn.replace(">=", "<")
                Expn = Expn.replace(">", "<")
                pseudoc = r"""void main()
                {
                if("""
                pseudoc += Expn
                pseudoc += r""")
                ;
                }
                """
            elif ((Expn.find("<") > -1) and (Expn.find("<<") < 0)):
                Expn = Expn.replace("<=", ">")
                Expn = Expn.replace("<", ">")
                pseudoc = r"""void main()
                {
                if("""
                pseudoc += Expn
                pseudoc += r""")
                ;
                }
                """
            elif (Expn.find("|") > -1):
                print("Error: Right Now difference between logical Or and Bitwise Or is not implemented")
                pseudoc = r"""void main()
                {
                }
                """
            else:
                pseudoc = r"""void main()
                {
                if(("""
                pseudoc += Expn
                pseudoc += r""") == 0)
                ;
                }
                """
        return pseudoc
    
    
if __name__ == "__main__": main()
