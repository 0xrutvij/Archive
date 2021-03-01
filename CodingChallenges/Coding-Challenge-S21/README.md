# ACM Research Coding Challenge (Spring 2021)



## Submission Procedure
4. Submit your solution by filling out this [form](https://acmutd.typeform.com/to/uqAJNXUe).

## Question One

Genome analysis is the identification of genomic features such as gene expression or DNA sequences in an individual's genetic makeup. A genbank file (.gb) format contains information about an individual's DNA sequence. The following dataset in `Genome.gb` contains a complete genome sequence of Tomato Curly Stunt Virus. 

**With this file, create a circular genome map and output it as a JPG/PNG/JPEG format.** We're not looking for any complex maps, just be sure to highlight the features and their labels.

**You may use any programming language you feel most comfortable. We recommend Python because it is the easiest to implement. You're allowed to use any library you want to implement this**, just document which ones you used in this README file. Try to complete this as soon as possible.

Regardless if you can or cannot answer the question, provide a short explanation of how you got your solution or how you think it can be solved in your README.md file. However, we highly recommend giving the challenge a try, you just might learn something new!

![Circular Genome Map of Tomato Curly Stunt Virus](https://github.com/0xrutvij/Coding-Challenge-S21/blob/main/circularGenomeTCSV.png)

### Solution Approach

While multiple styles of genome maps seem to exist, the link to the GenBank dataset shows a basic representation with certain features from the genome highlighted and marked with the start and end points on the base pair sequence. https://www.ncbi.nlm.nih.gov/nuccore/NC_004675.1?report=graph

Emulating the approach used by NCBI, I reproduced the graphical representation to a circular genome map format and added some information found in various other genome maps, such as GC% per 100 base pairs and GC skew per 100 base pairs. 

The library used to create the circular genome map was the BioPython package, particularly its Genome Diagram module.

The package has methods to parse GenBank files and extract records, which can then be added to feature sets.

For the CDS overview, all the CDS features were collated on one track.

To better view the genes parallel to the CDS features, each gene feature was assigned a separate track.

Two more tracks one for the GC% and GC skew ratio were added.

All these tracks were then assembled in the GraphDiagram and the genome map generated.

The GC% and GC skew were calculated using methods supplied with the Biopython library under Bio.SeqUtils, combining the methods' output with the location range graphs were plotted using the GraphSet feature.

Both PDF and PNG versions of the diagram were written since the PNG version tends to give a poor resolution even at high dpi settings (forces the diagram to skew offcenter).

### References

The 'chunkstring()' function was found at the following link, a relatively concise implementation of the function I was attempting to write.
https://stackoverflow.com/questions/18854620/whats-the-best-way-to-split-a-string-into-fixed-length-chunks-and-work-with-the/18854817

The API for GenomeDiagram Module
https://biopython.org/docs/dev/api/Bio.Graphics.GenomeDiagram.html

Plotting Graphs using GraphSet etc.
http://biopython.org/DIST/docs/GenomeDiagram/userguide.pdf

Biopython Docs and Tutorials
http://biopython.org/DIST/docs/tutorial/Tutorial.html#sec336

Reportlab API docs
https://pyng.tech/docs/reportlab/lib/colors.m.html


