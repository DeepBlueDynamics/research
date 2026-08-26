#! /usr/bin/python

import jsonschema
import json
from glob import glob
from yaml import safe_load
from yaml.resolver import Resolver

# remove resolver entries for On/Off/Yes/No
for ch in "OoYyNn":
    if len(Resolver.yaml_implicit_resolvers[ch]) == 1:
        del Resolver.yaml_implicit_resolvers[ch]
    else:
        Resolver.yaml_implicit_resolvers[ch] = []
        for resolver in Resolver.yaml_implicit_resolvers[ch]:
            if resolver[0] != 'tag:yaml.org,2002:bool':
                Resolver.yaml_implicit_resolvers[ch].append(resolver)

with open("validation/aspn_schema.json") as f:
    schema = json.load(f)

for directory in ["measurements", "metadata", "types"]:
    for filename in glob(f"{directory}/*.yaml"):
        with open(filename) as f:
            print(f"Validating {filename}...")
            json_data = safe_load(f)
            jsonschema.validate(instance=json_data, schema=schema)

print("Validation successful.")
