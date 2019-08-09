/* testjson.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
 */
#pragma once

std::string test_literal_1 = R"EOS(
{
	"Name":"Xeno Campanoli",
	"Phone":"",
	"Email":"",
	"Address":"",
	"Summary":""
}
	)EOS";
std::string test_literal_2 = R"EOS(
{ "Name":"Xeno Campanoli" }
	)EOS";
std::string test_literal_3 = R"EOS(
{}
	)EOS";
std::string test_literal_4 = R"EOS(
{
	"Name":"Xeno Campanoli",
	"Education": [
		{"Institution":"University of Washington", "Certification":"Bachelor of Arts", "Subject":"Economics", "Secondary Interests":"Math","Comments":
			"General GPA 3.67, with 48 credits in mathematics (math GPA 3.81)"}
	],
	"SampleWork": []
}
	)EOS";
std::string test_literal_5 = R"EOS(
{
	"Name":"Xeno Campanoli",
	"Phone":"",
	"Email":"",
	"Address":"",
	"Summary":"",
	"Education": [
		{"Institution":"University of Washington", "Certification":"Bachelor of Arts", "Subject":"Economics", "Secondary Interests":"Math","Comments":
			"General GPA 3.67, with 48 credits in mathematics (math GPA 3.81)"}
	],
	"SampleWork": [
					{"Type":"","Brief":"","CodeURL":"","DemoURL":"","UniqueId":"",
					"Skills":["POSIX Shell","Bash","Ruby","Ruby TestUnit","Ruby Minitest","Ubuntu","CentOS","RedHat","MS OMS","git","github"]}
	],
	"Abstract":{"Idea":"Some Dictionary Field","Specifics":"TBD"}
}
	)EOS";
std::string test_literal_6 = R"EOS(
{ "Experience":"Bogus" }
	)EOS";
std::string test_literal_7 = R"EOS(
{
	"Name":"Xeno Campanoli",
	"Phone":"",
	"Email":"",
	"Address":"",
	"Summary":"",
	"Education": [
		{"Institution":"University of Washington",
			"Certification":"Bachelor of Arts", "Subject":"Economics", "Secondary Interests":"Math",
			"Certification Month":"June 1982"
			"Comments":"General GPA 3.67, with 48 credits in mathematics (math GPA 3.81)"}
	],
	"SampleWork": [
					{"Type":"Hack","Brief":"Test but really nothing.","CodeURL":"","DemoURL":"","UniqueId":"",
					"Last Month":"May 2018",
					"Skills":["POSIX Shell","Bash","Ruby","Ruby TestUnit","Ruby Minitest","Ubuntu","CentOS","RedHat","MS OMS","git","github"]}
	],
	"Experience": [
		{	"Title":"Senior Consultant",
			"Client Organization":"Kestra Medical",
			"Payroll Organization":"Chameleon Technologies",
			"Begin Month":"February 2018",
			"End Month":"March 2018", 
			"Summary":"Aided with Build system on leaving by existing engineer.",
			"Anecdotes": [
						{  "Description":"Assistance with company automated build and test system.",
							"Skills":["Ubuntu","Jenkins","KVM","Bash"]
						}
						],
			"Supervisor Name":"Erick Roane",
			"Supervisor Email":"erick.roane@kestramedical.com",
			"Address":"11250 Kirkland Way Suite 100",
			"City":"Kirkland, WA",
			"Mail Code":"98033",
			"Phone":"(425) 279-8002"
		}
		]
}
	)EOS";

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of testjson.hpp
