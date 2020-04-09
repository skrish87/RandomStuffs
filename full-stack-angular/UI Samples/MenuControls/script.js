(function() {
    var isLeftMenuOpen = false;
    var isLeftMenuClickOpen = false;
    var isLeftMenuIconClicked = false;
    var initiate = function() {
        $('#leftMenu').hide();
        $('#leftMenuClick').hide();
        $('#leftMenu .icon').click(function(){
            isLeftMenuIconClicked = true;
            if (!isLeftMenuClickOpen) {
                $( "#main" ).animate({ "left": "+=274px" }, "fast", function() {
                    $('#leftMenuClick').show();
                });
                isLeftMenuClickOpen = true;
            }
        });
        $('#hotspot').mouseover(function(){
            if (!isLeftMenuOpen) {
                $('#leftMenu').show();
                isLeftMenuOpen = true;
            }
        });
        $('#main').mouseover(function(){
            if (isLeftMenuOpen && !isLeftMenuClickOpen) {
                $('#leftMenu').hide();
                isLeftMenuOpen = false;
            }
        });
        $('#closeButton').click(function(){
            if (isLeftMenuClickOpen) {
                $( "#main" ).animate({ "left": "-=274px" }, "fast", function() {
                    $('#leftMenuClick').hide();
                });
                isLeftMenuClickOpen = false;
            }
            if (isLeftMenuOpen) {
                $('#leftMenu').hide();
                isLeftMenuOpen = false;
            }
        });
    };

    $( document ).ready(function() {
        initiate();
    });
})();