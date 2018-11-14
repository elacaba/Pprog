#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

enum keys {UP, DOWN, LEFT, RIGHT};

int main(void)
{
	int width=3096;
	int height=2048;

	bool done= false;
	int pos_x= width/2;
	int pos_y= height/2;

	bool keys[4]= {false, false, false, false}; 

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
   al_install_keyboard();

   event_queue = al_create_event_queue();

   al_register_event_source(event_queue, al_get_keyboard_event_source());
   al_register_event_source(event_queue, al_get_display_event_source(display));

   while(!done){

   	ALLEGRO_EVENT ev;
   	al_wait_for_event(event_queue, &ev);

   	if(ev.type == ALLEGRO_EVENT_KEY_DOWN){

   		switch(ev.keyboard.keycode){
   			case ALLEGRO_KEY_UP:
   			keys[UP]= true;
   			break;

   			case ALLEGRO_KEY_DOWN:
   			keys[DOWN]= true;
   			break;

   			case ALLEGRO_KEY_LEFT:
   			keys[LEFT]= true;
   			break;

   			case ALLEGRO_KEY_RIGHT:
   			keys[RIGHT]= true;
   			break;


   		}
   	}else if(ev.type== ALLEGRO_EVENT_KEY_UP){

   		switch(ev.keyboard.keycode){
   			case ALLEGRO_KEY_UP:
   			keys[UP]= false;
   			break;

   			case ALLEGRO_KEY_DOWN:
   			keys[DOWN]= false;
   			break;

   			case ALLEGRO_KEY_LEFT:
   			keys[LEFT]= false;
   			break;

   			case ALLEGRO_KEY_RIGHT:
   			keys[RIGHT]= false;
   			break;

   			case ALLEGRO_KEY_ESCAPE:
   			done=true;
   			break;

   		}

   	}else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
   		done = true;
   	}

   	pos_y -= keys[UP]*30;/*if keys[up] is true then is equal to 1, if not it's equal to zero, so the square wont move*/
   	pos_y += keys[DOWN]*30;
   	pos_x -= keys[LEFT]*30;
   	pos_x += keys[RIGHT]*30;

   	al_draw_filled_rectangle(pos_x, pos_y, pos_x + 100, pos_y + 100, al_map_rgb(255, 178, 102));
   	al_flip_display();
   	al_clear_to_color(al_map_rgb(0,0,0));
   	

   }

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	al_uninstall_keyboard();

	
	return 0;
}