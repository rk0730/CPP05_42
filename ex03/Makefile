CXX := c++
CFLAGS := -std=c++98 -Wall -Wextra -Werror

SRCDIR := .
SRCS += $(SRCDIR)/main.cpp
SRCS += $(SRCDIR)/Bureaucrat.cpp
SRCS += $(SRCDIR)/AForm.cpp
SRCS += $(SRCDIR)/ShrubberyCreationForm.cpp
SRCS += $(SRCDIR)/RobotomyRequestForm.cpp
SRCS += $(SRCDIR)/PresidentialPardonForm.cpp
SRCS += $(SRCDIR)/Intern.cpp

OBJDIR := objs
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CFLAGS) -c -MMD -MP $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
