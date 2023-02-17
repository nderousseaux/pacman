CC			:= g++
TARGET		:= PacMan

#Directories
DIR			:= code
SRCDIR		:= $(DIR)/src
INCDIR		:= $(DIR)/includes
OBJDIR		:= out
TARGETDIR	:= .

#Flags
CFLAGS		:= -Wall -Wextra -Werror -I$(INCDIR) -I$(INCDIR)/moveables -std=c++11

#Files
SRCS		:= $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp) 
OBJS		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SRCS)))
INCLUDES	:= $(wildcard $(INCDIR)/*.h) $(wildcard $(INCDIR)/**/*.h)

#Rules
all: $(TARGETDIR)/$(TARGET)

debug: CFLAGS += -g
debug: $(TARGETDIR)/$(TARGET)

$(TARGETDIR)/$(TARGET): $(OBJS) #On construit l'executable
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 

$(OBJDIR)/%.o: $(SRCDIR)/**/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(OBJS)
