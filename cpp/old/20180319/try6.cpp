#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

using namespace std;

int main() {
  //string text ="{ \"people\": [{\"id\": 1, \"name\":\"MIKE\",\"surname\":\"TAYLOR\"}, {\"id\": 2, \"name\":\"TOM\",\"surname\":\"JERRY\"} ]}";
  string text ="{ \"1\": {\"name\":\"MIKE\",\"surname\":\"TAYLOR\"}, \"2\": {\"name\":\"TOM\",\"surname\":\"JERRY\"} }";
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse( text, root );
  if ( !parsingSuccessful )
  {
    cout << "Error parsing the string" << endl;
  }

  for( Json::Value::const_iterator outer = root.begin() ; outer != root.end() ; outer++ )
  {
    cout << outer.key() << ": " << *outer << endl;
    for( Json::Value::const_iterator inner = (*outer).begin() ; inner!= (*outer).end() ; inner++ )
    {
      cout << inner.key() << ": " << *inner << endl;
    }
  }
 string sb = root["people"];
 cout << "trace name:  " << sb << endl;
}
