#!/usr/bin/env python

course = Course()
course.add_source("git", "..")

# part 1
course.add_module("fundamentals")
course.add_module("objects")
course.add_module("coretypes")

# part 2
course.add_module("widgets")
course.add_module("painting")
course.add_module("appcreation")

# part 3
course.add_module("dialogs")
course.add_module("modelview")
course.add_module("dataio")

# part 4
course.add_module("graphicsview")

course.compile()
