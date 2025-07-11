#set global $global_main_panel_classes = 'col-md-6 col-lg-7 col-xl-8 col-xxl-9 mt-1'
#set global $global_main_panel_id = 'mainPanel'
#set global $global_main_container_classes = 'container-fluid'
#set global $global_station_info_classes = 'd-flex align-items-center stationInfo my-1'
#set global $display_gauge_panel = 'd-none'
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>$gettext("Page Title") $station.location</title>
    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css?v=$css_mtime" rel="stylesheet">
    <link href="css/bootstrap-icons.min.css?v=$css_mtime" rel="stylesheet">
    <link href="css/live.css?v=$css_mtime" rel="stylesheet">
    #set $extra_css = $to_list($Extras.get('extra_css', []))
    #for $css in $extra_css
    <link href="css/$css?v=$css_mtime" rel="stylesheet">
    #end for
    #set $extra_js = $to_list($Extras.get('extra_js', []))
    #for $js in $extra_js
    <script src="js/$js?v=$js_mtime"></script>
    #end for
    <script type="text/javascript">
    let locale = "$locale";
    let jsLocale = locale.replace("_", "-").split(".")[0];
    function decodeHtml(html) {
        var txt = document.createElement("textarea");
        txt.innerHTML = html;
        return txt.value;
    }
    function setToolboxVisibility(chartDiv, show) {
        try {
            let chart = charts[chartDiv.id];
            chart.setOption({
                toolbox: { show: show }
            });
        } catch(e) {
            //not ready
        }
    }
    let updateFunctions = [];
    </script>
</head>
