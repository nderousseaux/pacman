CC			:= g++
TARGET		:= pacman

#Directories
SRCDIR		:= src
INCDIR		:= $(SRCDIR)/includes
OBJDIR		:= out
TARGETDIR	:= .

#Flags
CFLAGS		:= -Wall -Wextra -Werror -I$(INCDIR)

#Files
SRCS		:= $(wildcard $(SRCDIR)/*.cpp)
OBJS		:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
INCLUDES	:= $(wildcard $(INCDIR)/*.h)

#Rules
all: $(TARGETDIR)/$(TARGET)

debug: CFLAGS += -g
debug: $(TARGETDIR)/$(TARGET)

$(TARGETDIR)/$(TARGET): $(OBJS) #On construit l'executable
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2 -lSDL2_image

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp #On construit le reste
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f $(OBJS)
