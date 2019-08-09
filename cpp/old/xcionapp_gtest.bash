#!/bin/bash
#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# xcionapp_gtest.bash

# Internal Procedures

abortIfNonzero() {
    _eNo=$1
    _eMsg=$2


    if (( _eNo == 0 ))
    then 
        echo "$_eMsg Successful."
        return 0
    else
        echo "FAILURE:  $_eMsg."
        cat <<EOABORTMSG
Errorno value was $_eNo."
Aborting inittesttools.bash.  Please excuse this primitive abort procedure.
Please try to fix the problem, get to an initial state, and try again.
EOABORTMSG
        exit 9
    fi
}

printUsage() {
cat <<EOUS
USAGE:  $0 [command line qualifiers]
    -a <app directory under which gtest is to be installed (defaults to \$PWD)>
    -h Print this usage statement.
EOUS
}

# Initializations

APPDIRECTORY=$PWD

while getopts ":a:h" opt; do
  case $opt in
    a)
        APPDIRECTORY=$OPTARG
    h)
        printUsage
        exit 0
        ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

readonly APPDIRECTORY

# Main Procedure

pushd $APPDIRECTORY
git clone https://github.com/google/googletest.git
abortIfNonzero $? "git clone of googletest"

cd googletest
abortIfNonzero $? "change directory into $APPDIRECTORY/googletest"
cmake CMakeLists.txt 
abortIfNonzero $? "cmake on the CMakeLists.txt in $APPDIRECTORY/googletest"
make
abortIfNonzero $? "make (gtest)"
popd
echo "gtest was apparently installed and build successfully in the $APPDIRECTORY."

# End of xcionapp_gtest.bash
