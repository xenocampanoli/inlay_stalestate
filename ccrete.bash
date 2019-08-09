#!/bin/bash
#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# ccrete.bash copy (quickly secrete) your resin data into your instantiated
# resumes, and other materials.

# Global Identifiers

readonly THISFOLDER=$(dirname $0)
Verbose=false

# Internal Procedures

printUsage() {
	echo 
}

# Script Initializations

while getopts ":a" opt; do
  case $opt in
    a)
      echo "-a was triggered!" >&2
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

# Main Procedure

#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# End of ccrete.bash
