#pragma once

#include<string>


char home_page [] = "<!DOCTYPE html>\
                      <html> \
              <head> \
              <meta name=\"viewport\" content=\"width=device-width, initial-scale=1 \"> \
              <style>\
                html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\
                .lton  { background-color:rgb(32, 45, 107) border: none; color: white; padding:16px40px;text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }     \
                .ltoff { background-color: #555555; padding: 16px 40px; color: white;}\
                .ltcoff{ background-color:rgb(200,200,200); padding: 16px 40px; font-size: 20px;}\
              </style>\
            </head> <body>\
    <h1> Lights</h1> click on.\
    <form action=\"/LT\" method=\"get\">\
    <fieldset style=\"background: #f6f8ff; border: 2px solid #4238ca;\">\
      <legend>Light control panel</legend>\
      <button type=\"submit\" class= \"lton\">lt</button>\
    </fieldset>\
    </form>\
    <form action=\"/STRIP\" method=\"get\">\
    <fieldset style=\"background: #f6f8ff; border: 2px solid #4238ca;\">\
      <legend>LED Strip control panel</legend>\
      <button type=\"submit\" class= \"lton\" >LED STRIP</button>\
    </fieldset>\
    </form>\
  </body>\
  </html>";
  
