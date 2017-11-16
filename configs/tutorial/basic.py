import m5
from m5.objects import *

root = Root(full_system=False)

# Hello object has been defined in src/hpca_tutorial folder
root.something_random = HelloObject()

m5.instantiate()
print "Beginning simulation"
exit_event = m5.simulate()
print "Exiting @ tick %i because %s" % (m5.curTick(), exit_event.getCause())