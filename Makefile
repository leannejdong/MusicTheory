CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCDIR = src
BUILDDIR = build
TARGETDIR = bin

SRCEXT = c
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TARGETS = $(patsubst $(SRCDIR)/%,$(TARGETDIR)/%,$(SOURCES:.$(SRCEXT)=))

.PHONY: all clean

all: $(TARGETS)

$(TARGETDIR)/%: $(BUILDDIR)/%.o
	@mkdir -p $(@D)
	$(CC) $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning..."
	$(RM) -r $(BUILDDIR) $(TARGETDIR)
