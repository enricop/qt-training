Mapviewer Lab from GraphicsView Details.

Starting with handout/mapviewer, add zooming controls.
use QGraphicsLayout to lay the widgets out properly.

NOTE: if you are unable to see a map when you run the handout,
this is probably beacuse the executable working directory is
not in the same location as Groland_map.png. To resolve this issue,
you may want to consider creating a resource, adding the map to that
and using :/Groland_map.png for the filename.

Step 1: Implement missing methods in MapControllerItem.cpp
Step 2: Modify main.cpp and create/add the item to a scene.


Suggested widgets:
    QPushButtons for +/-
    QSlider for selecting zoom level

Get the mouse to work like a "hand-grab" tool on drag, and
"move" the map so we can see different zoomed areas?

Extra credit: make scrollbars appear and disappear at the right times, and
indicate the correct scale of the ViewPort


