/*
 * PackageLicenseDeclared: Apache-2.0
 * Copyright (c) 2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mbed-drivers/mbed.h"

static void blinky(void) {
    static DigitalOut led(YOTTA_CFG_LED_PIN);

    led = !led;
    printf("LED = %d \n\r",led.read());
}

void app_start(int, char**){
    // set 115200 baud rate for stdout
    static Serial pc(USBTX, USBRX);
    pc.baud(115200);
    minar::Scheduler::postCallback(blinky).period(minar::milliseconds(500));
}

