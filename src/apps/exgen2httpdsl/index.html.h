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

#define FORM_HEADER "<form id='generator_form' method='post' action='/v0/gen.sl'>"

#define SELECT_SUBJECT "<select id='subject' name='subject' required='required' \
    onChange='showLevelSelector(this)'> \
      <option value='addition'>Easy Addition</option> \
      <option value='subtraction'>Easy Subtraction</option> \
      <option value='arithmetic'>Arithmetic</option> \
      <option value='multiplication'>Multiplication</option> \
    </select>"

#define ADDITION_SELECT_LEVEL "<select class='level' id='addition_level' name='addition_level'> \
      <option value='0'>Adding digits sum less than 10</option> \
      <option value='1'>Adding digits sum less than 20</option> \
      <option value='2'>Adding digits sum less than 20 two level</option> \
      <option value='3'>Addition with some carry</option> \
    </select>"

#define SUBTRACTION_SELECT_LEVEL "<select class='level' id='subtraction_level' style='display:none' name='subtraction_level'> \
      <option value='0'>Plus minus</option> \
      <option value='1'>Subtract digits</option> \
      <option value='2'>Subtract digits from number</option> \
      <option value='3'>Add 9 (-1)</option> \
      <option value='4'>Add 8 (-2)</option> \
      <option value='5'>Add 7 (-3)</option> \
      <option value='6'>Add 6 (-4)</option> \
      <option value='7'>Subtract digit from number</option> \
      <option value='8'>very long plus and minus</option> \
    </select>"
#define ARITHMETICS_SELECT_LEVEL "<select class='level' id='arithmetic_level' style='display:none' name='arithmetic_level'> \
      <option value='0'>Some carry</option> \
      <option value='1'>Alternating addition and subtraction level 1</option> \
      <option value='2'>Alternating addition and subtraction level 2</option> \
      <option value='3'>Alternating addition and subtraction level 3</option> \
      <option value='4'>Count by</option> \
    </select>"

#define MULTIPLICATION_SELECT_LEVEL "<select class='level' id='multiplication_level' style='display:none' name='multiplication_level'> \
      <option value='0'>Count by</option> \
      <option value='1'>Multiplication table</option> \
      <option value='2'>Multiply by 2</option> \
      <option value='3'>Multiply by 3</option> \
      <option value='4'>Multiply by 4</option> \
      <option value='5'>Multiply by 5</option> \
      <option value='6'>Multiply by 6</option> \
      <option value='7'>Multiply by 7</option> \
      <option value='8'>Multiply by 8</option> \
      <option value='9'>Multiply by 9</option> \
      <option value='9'>Multiply digit by digit</option> \
    </select>"

#define HTML_FOOTER "<input type='submit' value='Generate'> \
    <br> \
    </form> \
  </body> \
</html>"
