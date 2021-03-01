from reportlab.lib import colors
from reportlab.lib.units import cm
from Bio.Graphics import GenomeDiagram
from Bio import SeqIO
from Bio import SeqUtils
from Bio.Seq import Seq

col_list = [colors.coral, colors.blue, colors.crimson, colors.navy, colors.red, colors.lightskyblue]
itr = iter(col_list)
itr_copy = iter(col_list)

record = SeqIO.read("Genome.gb", "genbank")

track_list = []


cdsfs = GenomeDiagram.FeatureSet(name='CDS features')

for feature in record.features:
    if feature.type == "CDS":
        cdsfs.add_feature(feature, sigil="ARROW", color=next(itr_copy))

gdt1 = GenomeDiagram.Track('CDS features', greytrack=1, greytrack_labels=3)
gdt1.add_set(cdsfs)
track_list.append(gdt1)


for feature in record.features:
    if feature.type != "gene":
        continue
    gd_feature_set = GenomeDiagram.FeatureSet()
    gd_feature_set.add_feature(feature, sigil="ARROW", color=next(itr), label=True, label_size=15, label_angle=0)
    if(len(track_list) == 0 or len(track_list) == 4):
        track_for_this_feature = GenomeDiagram.Track(name=feature.qualifiers.get('gene'), scale=1, scale_fontsize=15, scale_ticks=1, scale_largeticks=0.5, scale_largetick_interval=500)
    else:
        track_for_this_feature = GenomeDiagram.Track(name=feature.qualifiers.get('gene'))
    track_for_this_feature.add_set(gd_feature_set)
    track_list.append(track_for_this_feature)



gdgs = GenomeDiagram.GraphSet('GC Content')

seq_string = str(record.seq)

def chunkstring(string, length):
    return (string[0+i:length+i] for i in range (0, len(string), length))

def gdps(str_list):
    ret_list = []
    i = 50
    for strng in str_list:
        ret_list.append((i, SeqUtils.GC(strng)))
        i = i + 100
    return ret_list

graphdata = gdps(chunkstring(seq_string, 100))

gdgs.new_graph(graphdata, 'GC Content', style='bar')

gdt2 = GenomeDiagram.Track('GC content', greytrack=1, greytrack_labels=4)
gdt2.add_set(gdgs)
track_list.append(gdt2)

def gcSkewData(lst):
    ret_list = []
    i = 50
    for x in lst:
        ret_list.append((i, x))
        i = i + 100
    return ret_list

graphdata2 = gcSkewData(SeqUtils.GC_skew(seq_string))

gdgs2 = GenomeDiagram.GraphSet('GC Skew')
gdgs2.new_graph(graphdata, 'GC Skew', style='line', linewidth=2)

gdt3 = GenomeDiagram.Track('GC Skew', greytrack=1, greytrack_labels=4)
gdt3.add_set(gdgs2)

track_list.append(gdt3)



gd_diagram = GenomeDiagram.Diagram("Tomato Curly Stunt Virus, complete genome", track_size=0.7)

i = 1

for track in track_list:
    gd_diagram.add_track(track, i)
    i = i + 1

gd_diagram.draw(
    format="circular",
    circular=True,
    pagesize=(50 * cm, 50 * cm),
    start=0,
    end=len(record),
    circle_core=0.3
)

gd_diagram.write("circularGenomeTCSV.pdf", "PDF", dpi=72)
gd_diagram.write("circularGenomeTCSV.png", "PNG", dpi=72)
