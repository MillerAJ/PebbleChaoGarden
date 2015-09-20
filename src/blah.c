#include <pebble.h>
  #include <stdlib.h>
static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *block_layer;
static BitmapLayer *s_background_layer;
static BitmapLayer *choa_layer;
static BitmapLayer *s_w_layer;
static BitmapLayer *fruit_layer;
static GBitmap *choa_bitmap;
static GBitmap *s_background_bitmap;
static GBitmap *s_w_bitmap;
static GBitmap *fruit_bitmap;

  int wait = 0;
  int food=0;
  int step=2;
  int sideStep=4;
  int sCount = 0;
  int X = 55;
  int Y = 60;

/*
static void back(){
        step =1;
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_BACK);
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
}
static void left(){
        step =1;
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_LEFT);
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
}
static void right(){
        step =1;
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_RIGHT);
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
}
static void idle(){
        step =1;
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_IDLE);
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
}
*/

static void idle_step(){
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        if(step%2==0){
            choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_IDLE_R);
        } else if (step % 2 ==1) {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_IDLE_L);
        }
        step+=1;
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        //bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
        if(Y<140){
          Y+=3;
        }
  }
static void back_step(){
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        if(step%2==0){
            choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_BACK_R);
        } else if (step % 2 ==1) {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_BACK_L);
        }
        step+=1;
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        //bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
        if(Y>11){
          Y-=3;
        }
  }
static void right_step(){
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        if(sideStep%4==0){
            choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_RIGHT_R);
        } else if (sideStep % 4 ==1) {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_RIGHT);
        } else if (sideStep%4==2) {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_RIGHT_L);
        } else {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_RIGHT);
        }
        sideStep+=1;
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        //bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
        if(X<114){
          X+=3;
        }
  }  
static void left_step(){
        bitmap_layer_destroy(choa_layer);
        gbitmap_destroy(choa_bitmap);
        if(sideStep%4==0){
            choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_LEFT_R);
        } else if (sideStep % 4 ==1) {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_LEFT);
        } else if (sideStep%4==2) {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_LEFT_L);
        } else {
          choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_LEFT);
        }
        sideStep+=1;
        choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
        bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
        //bitmap_layer_set_background_color(choa_layer, GColorClear);
        bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);
        layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(choa_layer));
        if(X>-8){
          X-=3;
        }
  } 


//====================== UPDATE Chao ===================
static void update_choa(){
  if (sCount == wait+2){
  bitmap_layer_destroy(fruit_layer);
  gbitmap_destroy(fruit_bitmap);
  bitmap_layer_destroy(s_w_layer);
  gbitmap_destroy(s_w_bitmap);
  }
  if (sCount ==60){
    sCount=0;
  }
  sCount+=1;
  if (sCount<=8||sCount>53){
    right_step();
  } else if(sCount>=9&&sCount<=23){
    idle_step();
  } else if(sCount>23&&sCount<=38){
    left_step();
  }else if(sCount>38&&sCount<=53){
    back_step();
  }
  
}


//============================UPDATE TIME====================================
static void update_time() {
  
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  // Create a long-lived buffer
  static char buffer[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_choa();
  update_time();
  
}



//============================================BUTTONS==========================================


void up_click_handler(ClickRecognizerRef recognizer, void *context)
{
   
}
 
void down_click_handler(ClickRecognizerRef recognizer, void *context)
{
  
}


void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
  
  bitmap_layer_destroy(fruit_layer);
  gbitmap_destroy(fruit_bitmap);
  bitmap_layer_destroy(s_w_layer);
  gbitmap_destroy(s_w_bitmap);
  
  
  food = rand()%101;
  
  if (food>0&&food<=50) {
       fruit_bitmap = gbitmap_create_with_resource(RESOURCE_ID_fruit1);
  } else if (food>50 && food <= 65) {
       fruit_bitmap = gbitmap_create_with_resource(RESOURCE_ID_fruit2);
  } else if(food>65 && food <= 90 ) {
     fruit_bitmap = gbitmap_create_with_resource(RESOURCE_ID_fruit3);
  } else if(food>90 &&food<100) {
     fruit_bitmap = gbitmap_create_with_resource(RESOURCE_ID_duck);
  } else {
    fruit_bitmap = gbitmap_create_with_resource(RESOURCE_ID_gba);
  }
  
  s_w_bitmap = gbitmap_create_with_resource(RESOURCE_ID_speech);
  s_w_layer = bitmap_layer_create(GRect(64, 47, 70, 70));
  bitmap_layer_set_bitmap(s_w_layer, s_w_bitmap);
  bitmap_layer_set_compositing_mode(s_w_layer, GCompOpSet);
  layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_w_layer));
  
  fruit_layer = bitmap_layer_create(GRect(63, 42, 70, 70));
  bitmap_layer_set_bitmap(fruit_layer, fruit_bitmap);
  bitmap_layer_set_compositing_mode(fruit_layer, GCompOpSet);
  layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(fruit_layer));  
  wait=sCount;
}



void click_config_provider(void *context)
{
    window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

//=============================================================================================

static void main_window_load(Window *window) {
  
  // Create time TextLayer
  s_time_layer = text_layer_create(GRect(0, 0, 144,50));
  //scroller_bar = text_layer_create(GRect(sBL, 125, 100, 20));

  text_layer_set_background_color(s_time_layer, GColorBlack);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  
  //===============LOAD BACKGROUND IMAGE==========================================================
  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_backGround);
  s_background_layer = bitmap_layer_create(GRect(0, 27, 144, 168));
    bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_background_layer));
  
  //=========LOAD CHOA IMAGE==================================================================
 choa_bitmap = gbitmap_create_with_resource(RESOURCE_ID_choa_IDLE);
  choa_layer = bitmap_layer_create(GRect(X, Y, 40, 40));
    bitmap_layer_set_bitmap(choa_layer, choa_bitmap);
      bitmap_layer_set_background_color(choa_layer, GColorClear);
  bitmap_layer_set_compositing_mode(choa_layer, GCompOpSet);

layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(choa_layer));



  // Improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
  //layer_add_child(window_get_root_layer(window), text_layer_get_layer(scroller_bar));
}

static void main_window_unload(Window *window) {
  // Destroy TextLayer
  bitmap_layer_destroy(s_background_layer);
  bitmap_layer_destroy(choa_layer);
    text_layer_destroy(s_time_layer);
    
  
}

static void init() {
    
  // Register with TickTimerService
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
 // tick_timer_service_subscribe(SECOND_UNIT, tick_handler2);
  //uint32_t timeout_ms = 750;
  //app_timer_register(timeout_ms, tick_handler2, NULL);
 
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_set_click_config_provider(s_main_window, click_config_provider);
  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
   // Make sure the time is displayed from the start
  update_time();
}

static void deinit() {
  // Destroy Window
    window_destroy(s_main_window);
    //text_layer_destroy(scroller_bar);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}