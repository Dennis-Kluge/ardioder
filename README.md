# ardioder
Just a simple implementation to connect two [IKEA Dioder](http://www.ikea.com/us/en/catalog/products/20119418/) light strips with an Arduino Uno. 

## Protocol 
The Protocol is pretty simple and ASCII based. It basiclly looks like that **S100200150000200150** which means nothing else then Start command (for syncing purposes) and send RGB values for each stripe. Each value consists of three digits a 0 is in that case a 000, 50 would be 050
