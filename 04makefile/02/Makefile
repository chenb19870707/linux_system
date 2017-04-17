SUBDIRS = test1 test2
.PHONY:default all clean $(SUBDIRS)
default:all

all clean:
	$(MAKE) $(SUBDIRS) TARGET=$@
$(SUBDIRS):
	$(MAKE) -C $@ $(TARGET)

