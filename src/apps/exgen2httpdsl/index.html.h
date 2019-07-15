#define HTML_HEADER_STRING "<html> \
  <head> \
    <title> \
    Exercise Generator \
    </title> \
  </head> \
  <body> \
    <script> \
    function showLevelSelector(selectEl) \
    { \
      let value = selectEl.options[selectEl.selectedIndex].value; \
      let level_selectors = document.getElementsByClassName('level'); \
      for (let i = 0; i < level_selectors.length; i += 1) \
      { \
        if (value + '_level' === level_selectors[i].id) \
        { \
          level_selectors[i].setAttribute('style', 'display:block'); \
        } \
        else \
        { \
          level_selectors[i].setAttribute('style', 'display:none'); \
        } \
      } \
    } \
    </script>"

#define FORM_HEADER "<form id='generator_form' method='post' action='/sssss/gen.sl'>"

#define SELECT_SUBJECT "<select id='subject' name='subject' required='required' \
    onChange='showLevelSelector(this)'> \
      <option value='addition'>Easy Addition</option> \
      <option value='subtraction'>Easy Subtraction</option> \
      <option value='arithmetic'>Arithmetic</option> \
      <option value='multiplication'>Multiplication</option> \
    </select>"

#define ADDITION_SELECT_LEVEL "<select class='level' id='addition_level' name='addition_level'> \
      <option value='1'>very Easy Addition</option> \
      <option value='2'>not so Easy Addition</option> \
      <option value='3'>vaery hard Addition</option> \
    </select>"

#define SUBTRACTION_SELECT_LEVEL "<select class='level' id='subtraction_level' style='display:none' name='subtraction_level'> \
      <option value='1'>very Easy Subtraction</option> \
      <option value='2'>not so Easy Subtraction</option> \
    </select>"
#define ARITHMETICS_SELECT_LEVEL "<select class='level' id='arithmetic_level' style='display:none' name='arithmetic_level'> \
      <option value='1'>very Easy Arithmetic</option> \
      <option value='2'>not so Easy Arithmetic</option> \
    </select>"

#define MULTIPLICATION_SELECT_LEVEL "<select class='level' id='multiplication_level' style='display:none' name='multiplication_level'> \
      <option value='1'>very Easy Multiplication</option> \
      <option value='2'>not so Easy Multiplication</option> \
    </select>"

#define HTML_FOOTER "<input type='submit' value='Generate'> \
    <br> \
    </form> \
  </body> \
</html>"
