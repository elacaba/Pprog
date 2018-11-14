#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;

   if(!al_init())
   {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   display = al_create_display(3000, 2000);

   if(!display)
   {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   al_init_font_addon();
   al_init_ttf_addon();
   al_init_primitives_addon();

   ALLEGRO_FONT * font14 = al_load_font("Gummy.ttf", 130, 0);

   al_clear_to_color(al_map_rgb(0,0,0));

   al_draw_filled_ellipse(1430, 800, 1500, 700, al_map_rgb(0, 153, 153));
   al_draw_text(font14, al_map_rgb(255, 153, 153), 1450, 750, ALLEGRO_ALIGN_CENTRE, "Welcome to the academy!");
   al_draw_line(550,850, 2350, 850, al_map_rgb(255, 153, 153), 7);


   al_flip_display();

   al_rest(5.0);

   al_destroy_display(display);
   al_destroy_font(font);

   return 0;

}