$fn = 50;
frameWidth = 110;
frameDepth = 160;
wheelRadius = 18;
motorDepth = 15;
motorWidth = 17;
boltRadius = 1.5;
boltEdgeDistance = 6;
wheelCaseWidth = 41;
wheelCaseDepth = 36;
wheelCaseCenterY = 30;

frameFilletRadius = 10;
wheelCaseFilletRadius = 5;
centerBarWidth = 8;

motorBottom = 70;
motorLeft = frameWidth/2 - motorWidth;

penHoleDiameter = 15;

// Maak een "frame" vorm. Deze vorm komt ook terug in het gat voor de wielen
module frame(width, depth, filletRadius){
        topCircleCenterDepth = depth - width/2;
    
        // De vorm bestaat uit de omtrek van drie cirkels
        hull() {            
            translate([-width/2 + filletRadius, filletRadius, 0])
                circle(r=filletRadius);
            translate([width/2 - filletRadius, filletRadius, 0])
                circle(r=filletRadius);
            translate([0, topCircleCenterDepth, 0])
                circle(d=width);
         
    }
}   

// Maak een wiel
module wheel(radius, holeRadius, holeHeight){
    // wiel met gat
    difference(){
        circle(r=radius);
        circle(holeRadius);
    }
    
    // maak het gat "plat"
    translate([-holeRadius, holeHeight/2, 0])
        square([holeRadius*2, holeRadius*2]);
    
    translate([-holeRadius, -holeHeight/2-holeRadius*2, 0])
        square([holeRadius*2, holeRadius*2]);
    
    // Maak het wiel vast aan het frame
    translate([0, radius-1, 0])
        square([1,2]);
    translate([0, -radius-1, 0])
        square([1,2]);
}

// De uitsparing voor het blauwe gedeelte van de stappenmotor met gaten voor de tie-wraps
module motorHole(){
    translate([0, motorDepth/2, 0]){
        square([motorWidth, motorDepth]);
        translate([motorWidth/2-1, -5, 0])
            square([14, 3], center = true);
        translate([motorWidth/2-1, motorDepth+5, 0])
            square([14, 3], center = true);
    }
    
    
}

// Gebruik de modules om het frame te maken
difference(){
    // Het frame
    frame(frameWidth, frameDepth, frameFilletRadius);
    
    // De uitsparingen voor de wielen
    translate([centerBarWidth/2,wheelCaseCenterY,0])
        rotate([0, 0, -90])
            frame(wheelCaseDepth, wheelCaseWidth, wheelCaseFilletRadius); //rechts
    
    translate([-centerBarWidth/2,wheelCaseCenterY,0])
        rotate([0, 0, 90])
            frame(wheelCaseDepth, wheelCaseWidth, wheelCaseFilletRadius); // links
    
    // De uitsparingen voor de stappenmotoren
    translate([motorLeft, motorBottom, 0]) // rechts
        motorHole();
    
    scale([-1, 1, 1]) // spiegelen voor links
        translate([motorLeft, motorBottom, 0])
            motorHole();
    
    // Het gat voor de pen
    translate([0, motorBottom + motorDepth, 0])
        circle(d=penHoleDiameter);
        
    // gaten voor de "sliders"
    translate([0, frameDepth-boltEdgeDistance, 0]) //voor
        circle(r=boltRadius); 
        
    translate([0, boltEdgeDistance, 0]) // achter
        circle(r=boltRadius);
        
    

}

// Rechter wiel
translate([centerBarWidth/2 + wheelCaseWidth/2, wheelCaseCenterY, 0])
    wheel(wheelRadius, 2.5, 3);   

// Linker wiel
scale([-1,1,1]) // spiegelen
    translate([centerBarWidth/2 + wheelCaseWidth/2, wheelCaseCenterY, 0])
            wheel(wheelRadius, 2.5, 3);  
