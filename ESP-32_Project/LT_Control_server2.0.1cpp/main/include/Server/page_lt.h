#pragma once

#include<string>
#include "LT.h"

//**********************************************************************//

bool LT_state[5] = {0, 0, 0, 0, 0};

std::string page_lt_0 = "<!DOCTYPE html>\
                      <html> \
              <head> \
              <meta name=\"viewport\" content=\"width=device-width, initial-scale=1 \"> \
              <style>\
                html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\
                .lton  { background-color:rgb(32, 45, 107) border: none; color: white; padding:16px40px;text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }\
                .ltoff { background-color: #555555; padding: 16px 40px; color: white;}\
                .ltcoff{ background-color:rgb(200,200,200); padding: 16px 40px; font-size: 20px;}\
              </style>\
            </head> <body>";
    

std::string page_lt_1 = "\
<h1> Lights</h1> click on.\
<form action=\"/LT\" method=\"get\">\
<fieldset style=\"background: #f6f8ff; border: 2px solid #4238ca;\">\
<legend>Light control panel</legend>\
 STAIR LT ON <input type=\"submit\" name=\"lt1\" value = \"0\"  class= \"lton\"  >\ 
 STAIR LT OFF<input type=\"submit\" name=\"lt1\" value = \"1\"  class= \"ltoff\" >\ 
 ROOM VAM LT ON <input type=\"submit\" name=\"lt2\" value = \"0\"  class= \"lton\"  >\ 
 ROOM VAM LT OFF<input type=\"submit\" name=\"lt2\" value = \"1\"  class= \"ltoff\" >\ 
 ROOM BLUE LT ON <input type=\"submit\" name=\"lt3\" value = \"0\"  class= \"lton\"  >\ 
 ROOM BLUE LT OFF<input type=\"submit\" name=\"lt3\" value = \"1\"  class= \"ltoff\" >\ 
 LT4 ON <input type=\"submit\" name=\"lt4\" value = \"0\"  class= \"lton\"  >\ 
 LT4 OFF<input type=\"submit\" name=\"lt4\" value = \"1\"  class= \"ltoff\" >\ 
 LT5 ON <input type=\"submit\" name=\"lt5\" value = \"0\"  class= \"lton\"  >\ 
 LT5 OFF<input type=\"submit\" name=\"lt5\" value = \"1\"  class= \"ltoff\" >\ 
 BLINK ON <input type=\"submit\" name=\"lt_blink\" value = \"0\"  class= \"lton\"  >\ 
 BLINK OFF<input type=\"submit\" name=\"lt_blink\" value = \"1\"  class= \"ltoff\" >\
 </fieldset> </form>";


 std::string _page_lt() 
 { 
    std::string line = "<h1> Lights</h1> click on.\
    <form action=\"/LT\" method=\"get\">\
    <fieldset style=\"background: #f6f8ff; border: 2px solid #4238ca;\">\
    <legend>Light control panel</legend>";

    std::string line0;
    if(lightcontext.get(0)) line0 = "ROOM VAM LT ON <input type=\"submit\" name=\"lt1\" value = \"0\"  class= \"lton\">";
        else        line0 = "ROOM VAM LT OFF<input type=\"submit\" name=\"lt1\" value = \"1\"  class= \"ltoff\">";
    
    std::string line1;
    if(LT_state[1]) line1 = "ROOM BLUE LT ON <input type=\"submit\" name=\"lt2\" value = \"0\"  class= \"lton\" >";
        else        line1 = "ROOM BLUE LT OFF<input type=\"submit\" name=\"lt2\" value = \"1\"  class= \"ltoff\">"; 
    
    std::string line2 = "</fieldset> </form>";

    line += line0;
    line += line1;
    line += line2;

    return line;
}

std::string page_lt_2 = "<form action =\"/\" method=\"get\">\
                         <button> Home </button>\
                      </form>\
                    </body>\
                   </html>";


const char* page;
std::string page_lt;

const char* LT_page()
{
    page_lt.clear();
    page_lt += page_lt_0;
    page_lt += _page_lt();
    page_lt += page_lt_2;

    page = page_lt.c_str();   
    return page;
}

