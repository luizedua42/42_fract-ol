NAME = fractol
NAMEBONUS = fractol_bonus
CC = cc
CCFLAGS = -Wall -Werror -Wextra
XFLAGS = -lmlx -lXext -lX11 -lm

OBJ = $(SRC:%.c=%.o)

BOBJ = $(BSRC:%.c=%.o)

BSRC = ext_funcs_bonus.c fractal_draw_bonus.c fract-ol_bonus.c julia_bonus.c \
	key_movement_bonus.c main_bonus.c mandelbrot_bonus.c mouse_zoom_bonus.c

SRC = ext_funcs.c fractal_draw.c fract-ol.c julia.c key_handling.c main.c \
	mandelbrot.c mouse_zoom.c

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(XFLAGS) -o $(NAME)

$(NAMEBONUS) : $(BOBJ)
	$(CC) $(CCFLAGS) $(BOBJ) $(XFLAGS) -o $(NAMEBONUS)

bonus: $(NAMEBONUS)

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)

re: fclean all 

.PHONY: all bonus clean fclean re