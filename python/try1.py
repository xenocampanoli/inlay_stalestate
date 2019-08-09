
import json
 
json_data = '{"name": "Brian", "city": "Seattle"}'
python_obj = json.loads(json_data)
print python_obj["name"]
print python_obj["city"]


array = '{"drinks": ["coffee", "tea", "water"]}'
data = json.loads(array)
 
for element in data['drinks']:
    print element

json_input = '{"persons": [{"name": "Brian", "city": "Seattle"}, {"name": "David", "city": "Amsterdam"} ] }'
 
try:
    decoded = json.loads(json_input)
 
    # Access data
    for x in decoded['persons']:
        print x['name']
 
except (ValueError, KeyError, TypeError):
    print "JSON format error"

json_data = '{"name": "Brian", "city": "Seattle"}'
python_obj = json.loads(json_data)
print json.dumps(python_obj, sort_keys=True, indent=4)

with open('../bole/draft0.json') as f:
	read_data = f.read()
print read_data
