# Cell data structure #

Cells are stored by cellID (an integer) in the 'world', which is a hash table. A cell has an internal representation of its own ID, which is important because not only does it let us do sanity checks, but the special value of -1 will tell us that the cell is a dummy created for the sake of some other cell and that we need to pull the real content from the database before we render it.

We can assume that the database will store only posward links. So, the negward links need to be figured out. The database can be queried if we have constructed a cell that links negwardly on a visible dimension to another cell that has not yet been loaded.

We will load cell content from database as-needed.

# Corner cases #

If we change the negward link on a rendered cell such that it links to an already existent but not loaded cell, we will have some trouble. In this corner case we will need to load this cell before doing the link stuff.

# Modularity #

## Lib ##

The ZZ Cell implementation, the ZZ Graph Walker, and an abstract ZZ Backend that Graph Walker uses. The Graph Walker MAY also walk a list of ZZ Cell's in lieu of a backend. The dynamic library is currently libzz.so

## Backends ##

Depends on libzz for the ZZ Cell implementation.

Currently only a SQL backend is being implemented. Any number of which are possible, and any number may be linked in at compile time. The dynamic library will be libzzbackend-sql.so.

## Frontends ##

Depends on libzz and at least one Backend.

Currently only a Qt GUI is in progress.

A Cache Manager will cache QSharedPointers of both ZZ Cells and ZZ Graphics Cells. It will manage dirty cells and write changes back to the Backend every five seconds, or through an explicit flush. The cache MAY be bypassed in the case of an in-memory Backend.

# UI #

Modes:
  * row mode - default, truncates text and resizes other stuff to a static square or rectangle, show however many things around cursor as fit, highlight around square for cursor (or use gzz's blue/green thing)
![http://dimscape.googlecode.com/svn/trunk/docs/row.gif](http://dimscape.googlecode.com/svn/trunk/docs/row.gif)
  * z2 mode - square sized to content, display only the posward and negward links from the cell with the cursor
![http://dimscape.googlecode.com/svn/trunk/docs/xbar.gif](http://dimscape.googlecode.com/svn/trunk/docs/xbar.gif)
  * expanding mode - the cell with the cursor is bigger and fully opaque. As you get further away from the current/cursor cell the cells get smaller and more transparent. The cell still fits to content, but the content is scaled down. Smaller cells are drawn first, and bigger cells are drawn on top of them.
![http://dimscape.googlecode.com/svn/trunk/docs/expand.gif](http://dimscape.googlecode.com/svn/trunk/docs/expand.gif)

# Pretty Pictures #

![http://dimscape.googlecode.com/svn/trunk/dimscape-logo-notrans.png](http://dimscape.googlecode.com/svn/trunk/dimscape-logo-notrans.png)
White background

![http://dimscape.googlecode.com/svn/trunk/dimscape-logo.png](http://dimscape.googlecode.com/svn/trunk/dimscape-logo.png)
Transparent background

http://dimscape.googlecode.com/svn/trunk/dimscape-logo.xpm
XPM file