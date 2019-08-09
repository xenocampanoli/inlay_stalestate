1.  Bake should contain the cli handling and read the resin and the template files into their respective resin and mold objectcrucibles.
    i.  Reads in command line arguments to define function.
    ii.      resin class
        a.  receives resin file paths.
        b.  receives dictionary with identifier and validation typing pairs.
        c.  validates and makes object constant at instantiation if it can finish.
        d.  verbose reporting of content available (data dumps)
        e.  string replace function for identifiers so that client provides an abstract and receives finished text; the amber, so to speak.
        f.  Make for recursive replacement.
        g.  Make for dynamic validation lists from templates.
    iii.     mold class
        a.  reads the template file into a mold object
		b.	fully validates the template directory
			i.		Reading in Required JSON
			ii.		Loading the Main text.
			iii.	Loading a template for each list section.
			iv.		Provide validation method for a bolesap item and a soilsap item.
			v.		Provide the mixBake method to create the "Amber" object.
        b.  calls the resin method with each template section with recursive calls to sub areas.
        c.  writes concrete output file
    iv.    mildew class
        a.  reads site map file for a web site.
        b.  paints resin data into the web site and automatically submits an application
    v.  

Done for now:
