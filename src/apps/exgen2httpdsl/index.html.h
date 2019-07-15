"<html> \
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
    </script> \
To generate exercises, select the subject and the level and hit submit \
    <br> \
    <form id='generator_form' method='post' action='/sssss/gen.sl'> \
    <select id='subject' name='subject' required='required' \
    onChange='showLevelSelector(this)'> \
      <option value='addition'>Easy Addition</option> \
      <option value='subtraction'>Easy Subtraction</option> \
      <option value='arithmetics'>Arithmetic</option> \
      <option value='multiplication'>Multiplication</option> \
    </select> \
    <br> \
    <select class='level' id='addition_level' name='addition_level'> \
      <option value='1'>very Easy Addition</option> \
      <option value='2'>not so Easy Addition</option> \
      <option value='3'>vaery hard Addition</option> \
    </select> \
    <select class='level' id='subtraction_level' style='display:none' name='subtraction_level'> \
      <option value='1'>very Easy Subtraction</option> \
      <option value='2'>not so Easy Subtraction</option> \
    </select> \
    <select class='level' id='arithmetics_level' style='display:none' name='arithmetics_level'> \
      <option value='1'>very Easy Arithmetic</option> \
      <option value='2'>not so Easy Arithmetic</option> \
    </select> \
    <select class='level' id='multiplication_level' style='display:none' name='multiplication_level'> \
      <option value='1'>very Easy Multiplication</option> \
      <option value='2'>not so Easy Multiplication</option> \
    </select> \
    <br> \
    <input type='submit' value='Generate'> \
    <br> \
    </form> \
  </body> \
</html> \
"
