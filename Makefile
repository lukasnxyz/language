CC	= gcc
FLAGS	= -Wall -Wextra --std=c11
#LFLAGS =

ODIR = objs
SDIR = src

SRCS = $(wildcard $(SDIR)/*.c)
OBJS = $(wildcard $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS = $(wildcard $(SDIR)/*.h)

OUT	= main

all: $(ODIR) $(OUT)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "Created $(ODIR) directory"

$(OUT): $(OBJS)
	@echo "Linking object files into executable $(OUT)"
	$(CC) $(FLAGS) -o $@ $^ 

$(ODIR)%.o: $(SDIR)/%.c $(DEPS)
	@echo "Compiling $< into $@"
	$(CC) $(FLAGS) -c -o $@ $< 

clean:
	@echo "Cleaning up..."
	@rm -f $(ODIR)/*.o $(OUT)
	@rmdir $(ODIR)
