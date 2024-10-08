CC	= g++
FLAGS	= -Wall -Wextra --std=c++17
#LFLAGS =

ODIR = objs
SDIR = src

SRCS = $(wildcard $(SDIR)/*.cpp)
OBJS = $(wildcard $(SDIR)/%.cpp, $(ODIR)/%.o, $(SRCS))
DEPS = $(wildcard $(SDIR)/*.hpp)

OUT	= main

all: $(ODIR) $(OUT)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "Created $(ODIR) directory"

$(OUT): $(OBJS)
	@echo "Linking object files into executable $(OUT)"
	$(CC) $(FLAGS) -o $@ $^ 

$(ODIR)%.o: $(SDIR)/%.cpp $(DEPS)
	@echo "Compiling $< into $@"
	$(CC) $(FLAGS) -c -o $@ $< 

clean:
	@echo "Cleaning up..."
	@rm -f $(ODIR)/*.o $(OUT)
	@rmdir $(ODIR)
