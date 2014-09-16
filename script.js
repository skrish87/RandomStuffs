// JavaScript Document
var numberOfRows=30; // This number will be changed to control the number of rows
var activeTabId = "tab-1";


var constructTrRow = function(index) {
    var bgColor1 = "#FFFFFF";
    var bgColor2 = "#F4F4F4";
    var bgColor = (index%2 == 0) ? bgColor2: bgColor1;
    var trRowString = '<tr bgcolor="' + bgColor + '">' +
        '<td>' + index + '</td>' +
        '<td>The big black dog jumped over the lazy fox.</td>' +
        '</tr>';

    return trRowString;
}

var processTabClick = function(e) {
    if (e.target.id == activeTabId)
        return;
    $('#' + activeTabId).attr('src','images/darkGrayTab.png');
    activeTabId = e.target.id;
    $('#' + activeTabId).attr('src','images/whiteTab.png');
};

var processTabMouseOver = function(e) {
    if (e.target.id == activeTabId)
        return;
    $('#' + e.target.id).attr('src','images/lightGrayTab.png');
};

var processTabMouseOut = function(e) {
    if (e.target.id == activeTabId)
        return;
    $('#' + e.target.id).attr('src','images/darkGrayTab.png');
};


$( document ).ready(function() {
    $("img").click(function(e){
        if (e.target.id.indexOf("tab-") == -1)
            return;
        else
            processTabClick(e);
    });

    $("img").mouseover(function(e){
        if (e.target.id.indexOf("tab-") == -1)
            return;
        else
            processTabMouseOver(e);
    });

    $("img").mouseout(function(e){
        if (e.target.id.indexOf("tab-") == -1)
            return;
        else
            processTabMouseOut(e);
    });

    for (var i=1;i<=numberOfRows;i++) {
        if (i==1)
            $("#main-table").append(constructTrRow(i));
        else
            $('#main-table tr:last').after(constructTrRow(i));

    }
});