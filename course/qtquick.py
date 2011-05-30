#!/usr/bin/env python

course = Course()
course.add_source("git", "..")

# part 1
course.add_module("qml-intro")
course.add_module("qml-composing-uis")
course.add_module("qml-user-interaction")

# part 2
course.add_module("qml-states-transitions")
course.add_module("qml-animations")
course.add_module("qml-presenting-data")

# part 3
course.add_module("qml-structures")

# part 4
course.add_module("qml-cpp-integration")

course.compile()
