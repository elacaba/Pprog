#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>



int main(void)
{
	int width=3096;
	int height=2048;

	bool done= false;
   bool drawn= false;
	int pos_x= width/2;
	int pos_y= height/2;


	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue =NULL;

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

   al_init_primitives_addon();
   al_install_mouse();

   event_queue = al_create_event_queue();

   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_mouse_event_source());

   al_hide_mouse_cursor(display);

   while(!done){

   	ALLEGRO_EVENT ev;
   	al_wait_for_event(event_queue, &ev);

   	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
   		done = true;
   	}else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES){
         pos_x= ev.mouse.x;
         pos_y= ev.mouse.y;
      }else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
         if(ev.mouse.button & 2){
            done=true;
         }else if(ev.mouse.button & 1){
            drawn= !drawn;
         } /*button 1 is left, 2 is right*/
      }

      if(drawn)
   	  al_draw_filled_rectangle(pos_x, pos_y, pos_x + 100, pos_y + 100, al_map_rgb(255, 178, 102));

   	al_flip_display();
   	al_clear_to_color(al_map_rgb(0,0,0));
   	

   }

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	
	return 0;
}