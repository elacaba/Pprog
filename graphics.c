#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

int main(int argc, char **argv)
{


   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *queue =NULL;
   ALLEGRO_TIMER *timer ;
   ALLEGRO_BITMAP *bitmap =NULL;

   bool done = false;
   const int width= 3096;
   const int height = 2048;


   if(!al_init())
   {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   display = al_create_display(width, height);

   if(!display)
   {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   queue = al_create_event_queue();
 
  
   al_install_keyboard();
   al_install_mouse();

   al_register_event_source(queue, al_get_keyboard_event_source());
   al_register_event_source(queue, al_get_mouse_event_source());
   al_register_event_source(queue, al_get_display_event_source(display));
  

   al_init_image_addon();

   bitmap= al_load_bitmap("myimage.jpg");
   assert(bitmap!=NULL);

   float x=0, y=0;
   int widthscreen =al_get_display_width(display);

   

   while(!done){

      al_clear_to_color(al_map_rgb(1,1,1));
         al_draw_bitmap(bitmap, x, y, 0);
         al_flip_display();

      ALLEGRO_EVENT ev;
      al_wait_for_event(queue, &ev);

   if(ev.type== ALLEGRO_EVENT_DISPLAY_CLOSE){

         done=true;

   }else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES){
      x= ev.mouse.x;
      y= ev.mouse.y;
   

   } else if(ev.type == ALLEGRO_EVENT_TIMER){
         al_clear_to_color(al_map_rgb(1,1,1));
         al_draw_bitmap(bitmap, x, y, 0);
         al_flip_display();
      }
   
}


 al_destroy_display(display);
 al_uninstall_keyboard();
 al_uninstall_mouse();
 al_destroy_bitmap(bitmap);

 return 0;
}