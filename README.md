# cengine - simple & minimalistic graphics engine
Yes, that is pretty much all this is. Knock yourself out. Im trying to properly learn C so the code is not gonne be of good quality. 

TODO:
- Create moveable camera.
- Fill triangles.
- Implement normal vector for polygons.
- Only draw polygons that have normal towards camera, i.e. don't render polygons behind something.

:star:

## How do you project a 3D object to a screen? (2D)
You do some linear algebra. No but seriously, first you need to define what it is which you want to project, and to where.

Lets assume you have two points *u(x,y,z)* and *v(x,y,z)* in 3D space which you want to project onto your screen. First you need to define the screen and the axis orientations. Say that the x-axis and y-axis lies in the range [0, W] and [0, H] respectively. 
The first step is to normalize the screen coordinate to the range [-1, 1]. This means we ultimateley have a coordinte system where x increases from -1 to 1 horizontally to the right and y increases from -1 to 1 vertically down in the screen. Which means that the pixel at point (W, H) is mapped to (1, 1). 
When we have this we can define the aspect ratio *a* to be H/W. Since not all screens are symmetrical in width and height it is necessary to have the aspect ratio which we can mulitply x with to move the coordinate appropriately. 

Next we need to define the Field Of View (FOV). 
