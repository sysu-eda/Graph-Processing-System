# This code is part of the project "Krill"
# Copyright (c) 2029 Hongzheng Chen

import sys

path = sys.argv[1]
prefix = '/'.join(path.split("/")[:-1])
infile_name = sys.argv[1].split("/")[-1]
pb_name = infile_name.split(".")[0]

outfile_name = "{}.pb.h".format(pb_name)

head = """// Generated by the property buffer compiler. DO NOT EDIT!
// source: {0}

#ifndef {1}_PROPERTY_BUFFER_H
#define {1}_PROPERTY_BUFFER_H

#include <cctype>
#include <cstdlib>

namespace {2} {{

typedef unsigned int uintE;
""".format(infile_name,pb_name.upper(),pb_name)

tail = """
}} // namespace {0}

#endif // {1}_PROPERTY_BUFFER_H
""".format(pb_name,pb_name.upper())

job = "main"
props = []
with open(path,"r") as infile:
    for line in infile:
        line = line.strip()[:-1].split()
        if len(line) == 0:
            continue
        elif line[0] == "property":
            job = line[1]
        else:
            type_name , prop_name = line
            props.append((job,prop_name,type_name))

def get_prop_class(job,prop_name,type_name):
    class_name = "{}_{}".format(job,prop_name)
    res = "class {} {{\npublic:\n".format(class_name)
    res += "  {}(size_t n) {{\n".format(class_name)
    res += "    data = (uintE*) malloc(sizeof(uintE) * n);\n" \
           "  }\n" \
           "  inline uintE operator[] (int i) const { return data[i]; }\n" \
           "  inline uintE& operator[] (int i) { return data[i]; }\n" \
           "  uintE* data;\n" \
           "};\n\n"
    return res

def get_main_class():
    res  = "class Property {\npublic:\n  size_t n;\n" \
           "  Property(size_t _n): n(_n) {}\n"
    for prop in props:
        class_name = "{}_{}".format(prop[0],prop[1])
        prop_name = prop[1]
        res += "  inline {0}* add_{1}() {{\n".format(class_name,prop_name)
        res += "    {0}* {1} = new {0}(n);\n".format(class_name,prop_name)
        res += "    return {};\n".format(prop_name)
        res += "  }\n"
    res += "};\n\n"
    return res

with open(prefix + "/" + outfile_name,"w") as outfile:
    outfile.write(head)
    for prop in props:
        outfile.write(get_prop_class(prop[0],prop[1],prop[2]))
    outfile.write(get_main_class())
    outfile.write(tail)