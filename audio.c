#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int main(int argc, char **argv)
{

   bool done = false;
   const int width= 3096;
   const int height = 2048;

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *queue =NULL;
   ALLEGRO_SAMPLE *sample =NULL;
   ALLEGRO_SAMPLE_INSTANCE *sampleInstance = NULL;
  

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

   al_install_audio();
   al_init_acodec_addon();
   al_init_primitives_addon();
   al_install_mouse();

   al_reserve_samples(1);

   queue = al_create_event_queue();

   al_register_event_source(queue, al_get_display_event_source(display));
   al_register_event_source(queue, al_get_mouse_event_source());


   sample= al_load_sample("ghostloop.wav");

   /*sampleInstance = al_create_sample_instance(sample);
   al_attach_sample_instance_to_mixer(sampleInstance, al_get_default_mixer());
   al_play_sample_instance(sampleInstance);*/

   al_play_sample(sample, 1.0, 0,1, ALLEGRO_PLAYMODE_LOOP, NULL);

   /*while(al_get_sample_instance_playing(sampleInstance)){}*/

   while(!done){

      ALLEGRO_EVENT event;
      al_wait_for_event(queue, &event);

      if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
         done = true;

   }
}

   al_destroy_sample_instance(sampleInstance);
   al_destroy_sample(sample);
   al_uninstall_audio();

return 0;

}
