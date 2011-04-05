course = Course()

## edit the following line to point to your clone of the course material
course.add_source("git", "~/gitorious/course-material")

## optionally add your private repository
# course.add_source("svn", "~/qt-training-svn/trunk/course-material")

## select training modules to build (subfolders in course-material/slides)
course.add_module("fundamentals")
course.add_module("objects")

## second argument allows to specify a specific source
# course.add_module("widgets", 'svn')

course.compile()
