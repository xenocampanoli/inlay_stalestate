# Resinate - Making your resume from YAML or JSON.

## Overview

This is an interpolation application, designed to take patterns like:
@@@sometag@@@ and replace them with data referenced in a JSON data file under
the "sometag" reference.  The first place I ever saw this kind of usage
precisely was on the ShopNow.com project in Summer of 2000.  Other extensions
to this kind of pattern I then use include ###sometext###sometag###moretext###
for circumstances where the entire text area cited should be left out when no
sometag item in proper context is provided in the JSON, and where missing JSON
items should not result in an error.  ^^^sometag^^^ is then
used to take list items and paste them into a list according to a separate
sometag file defining format for each list item.  In list cases Topic labels
sublists may be provided that allow for filtering by topic.  Coming full circle,
the @@@sometag@@@ instances should always throw or exit with fatal errors if
no corresponding data item is found in the JSON.


## Intentions

The above summary needs to stay with as little added complexity as possible, as
the intent here is both has a personal tool that does not rob me of my time, and
as a concise clear example of constructs in the language of implementation.

My objectives with this project are to both demonstrate, and revive in my mind,
my skills in programming languages, mathematics, and other supporting areas.  I
hope especially to nail down C++, Python, Ruby and Go.  I would also like
examples in Julia and C, if that becomes practical.  Then I hope then to do
resume and history documents in HTML and LaTeX, but other formats are not out of
the question.  Tertiary languages of interest include Markdown, nroff, and wiki
language.  I may consider DocBook if prompted, but I never really liked it.  Most
other markup languages can be better covered with translaters from the primaries
I think.  I also hope to support all code with a popular test framework
corresponding to the language, and to maintain shell tests in Bats, shunit2, and 
acceptance test in Cucumber.  We'll see.  Tall orders.  In the end, all my resumes
and other lists should generate quickly across multiple threads in all languages
quickly, all at once, from a central run and performance test script.

## resinate shell script

### Templates

### Acception Tests in Cucumber

## Study of Python version

First To Be Coded

## Study of Ruby version

Second To Be Coded

## Study of Go version

(In my hopes)

## Study of Julia version

(In my dreams)

## Study of C version

(In my dreams)
