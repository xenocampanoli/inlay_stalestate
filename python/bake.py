#!/usr/bin/python3

import getopt
import glob
import os
import sys

# Primary Global Variables

GetOptFlags = 'hlLr:sSt:'
ResinRepositoryFolder = '../bole'

# Default Identifiers

DefaultResinFilename = 'resin.json'
DefaultResinFSpec = "%s/%s"%(ResinRepositoryFolder,DefaultResinFilename)

RFSpec = DefaultResinFSpec

TemplateFolder = '../templates'

def listResinDroplets(columnarList=False):
    if columnarList:
        for filename in glob.glob("%s/*.json" % ResinRepositoryFolder):
            print(filename)
    else:
        print(glob.glob("%s/*.json" % ResinRepositoryFolder))

def printUsage():
	print("""USAGE:  ./%s
	-h	Help (this document)
	-l list resin droplets available.
	-r <alternate template file> (default is %s).
	-s show list of all templates.
""" % (os.path.basename(__file__),DefaultResinFSpec))

def listTemplates(columnarList=False):
    if columnarList:
        for filename in glob.glob("%s/*" % TemplateFolder):
            print(filename)
    else:
        print(glob.glob("%s/*" % TemplateFolder))


def parseCLAsConcisely():
    try:
        opts, args = getopt.getopt(sys.argv[1:], GetOptFlags)
    except getopt.GetoptError as err:
        # print help information and exit:
        print(err) # will print something like "option -a not recognized"
        printUsage()
        sys.exit(2)
    output = None
    verbose = False
    for o, a in opts:
        if o == "-h":
            printUsage()
            sys.exit()
        elif o == "-l":
            listResinDroplets()
            sys.exit(0)
        elif o == "-L":
            listResinDroplets(True)
            sys.exit(0)
        elif o == "-s":
            listTemplates()
            sys.exit(0)
        elif o == "-S":
            listTemplates(True)
            sys.exit(0)
        elif o == "-t":
            TFSpec = "%s/%s" % (ResinRepositoryFolder,a)
        else:
            assert False, "Programmer ERROR:  bad command line qualifier"

def cookItUp():
    print("TBD:  cookItUp %s" % RFSpec)

if __name__ == "__main__":
    parseCLAsConcisely()
    cookItUp() 
