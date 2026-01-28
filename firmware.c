typedef enum {
    STATE_IDLE,
    STATE_LISTENING,
    STATE_ERROR
} DeviceState;

void device_loop(void)
{
    static DeviceState state = STATE_IDLE;
    static int hold_time = 0;
    int battery = get_battery_level();

    switch (state)
    {
        case STATE_IDLE:
            set_led_color(OFF);
            stop_audio_stream();

            if (battery < 10) {
                state = STATE_ERROR;
            }
            else if (button_pressed()) {
                state = STATE_LISTENING;
                hold_time = 0;
            }
            break;

        case STATE_LISTENING:
            set_led_color(GREEN);
            start_audio_stream();

            if (!button_pressed()) {
                state = STATE_IDLE;
            }
            else {
                hold_time++;
                if (hold_time > 30) {
                    state = STATE_IDLE;
                }
            }
            break;

        case STATE_ERROR:
            set_led_color(RED);
            stop_audio_stream();

            if (battery >= 10) {
                state = STATE_IDLE;
            }
            break;
    }
}
