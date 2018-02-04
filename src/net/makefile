

include ../makeinit

SRC  = $(shell find . -type f -name '*.cpp')
OBJS = $(SRC:.cpp=.o)

release: $(OBJS)
	@echo $(SRC)
	@echo $(OBJS)

%.o: %.cpp
	@echo Compile "$(*F)" ...
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

define dinc
-include $(1:.cpp=.d)
endef

$(foreach src, $(SRC), $(eval $(call dinc $(src))))

