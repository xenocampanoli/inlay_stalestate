#!/bin/bash
#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# inittesttools.bash

# Global Identifiers

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

installCriterionDebian() {

    sudo add-apt-repository -y ppa:snaipewastaken/ppa
    abortIfNonzero $? "Attempt to add snaipe repository"
    # Note:  To take the previous back out:
    # sudo add-apt-repository -ry ppa:snaipewastaken/ppa

    sudo apt-get update
    abortIfNonzero $? "Attempt to update with snaipe repository"

    sudo apt-get install criterion-dev
    abortIfNonzero $? "Attempt to install criterion-dev package"

    return 0
}

installGTestDebian() {

    sudo apt-get install libgtest-dev
    abortIfNonzero $? "Install libggtest-dev package"

    sudo apt-get install cmake # install cmake
    abortIfNonzero $? "Assure cmake package was installed"
    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    abortIfNonzero $? "Run cmake to set up gtest build"
    sudo make
    abortIfNonzero $? "make gtest"

    # copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
    sudo cp *.a /usr/lib
    abortIfNonzero $? "Copy *.a libraries for gtest to /usr/lib folder"
    return 0
}

installDebian() {
    sudo apt-get update
    abortIfNonzero $? "Simple initial apt-get update"
    sudo apt-get install bats
    abortIfNonzero $? "install bats package"
    sudo apt-get install shunit2
    abortIfNonzero $? "install shunit2 package"
    installCriterionDebian
    installGTestDebian
}

printUsage() {
	echo "USAGE:  $0"
}

# Script Initializations 


# Main Procedure

if (( $EUID != 0 ))
then
    echo "FATAL:  This script must be run with root privileges."
    exit 1
fi

if [[ -n $(grep Debian /etc/issue) ]]
then
    installDebian
elif [[ -n $(grep Ubuntu /etc/issue) ]]
then
    installDebian
else
    echo "ERROR:  inittesttools not programmed for present operating system."
fi 
echo "resinate inittesttools.bash script ran without seeing errors."

#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# End of inittesttools.bash
