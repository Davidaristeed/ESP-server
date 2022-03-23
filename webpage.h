//Webpage Code
//============
String webpageCode = R"***(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="page.css">
    <script src="page.js"></script>
</head>
<style>
    *
{
    margin: 0;
    padding: 0;
    font-family: 'Roboto',sans-serif;
}
section{
    position: relative;
    display: flex;
    justify-content: center;
    align-items: center;
    padding: 40px 0;
    min-height: 100vh;
    background: #350048;   
}
section::before{
    content: '';
    position: absolute;
    top: 45%;
    left: 0;
    width: 100%;
    height: 50px;
    background: #bd00ff;
}
.container{
    width: 900px;
    display: flex;
    flex-wrap: wrap;
    justify-content: space-around;
}
.container .card{
    position: relative;
    width: 250px;
    height: 300px;
    text-align: center;
    z-index: 10;
    margin: 20px 20px 60px;
}
.container .card .box{
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    display: flex;
    justify-content: center;
    align-items: center;
    background: rgba(255,255,255,0.05);
    box-shadow: 0 15px 35px rgba(0,0,0,0.5);
    backdrop-filter: blur(15px);
    border: 1px solid rgba(255,255,255,0.1);
    z-index: 10;
    border-radius: 10px;
}
.percent {
    position: relative;
    width: 150px;
    height: 150px;
    border-radius: 50%;
    z-index: 100;

}
.percent .number{
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    display: flex;
    justify-content: center;
    align-items: center;
}
.percent .number h2 {
    color: #fff;
    font-weight: 700;
    font-size: 50px;
}
.percent .number h2 span{
    font-size: 24px;
}
.text{
    position: absolute;
    bottom: -42px;
    left: 50%;
    transform: translateX(-50%);
    text-align: center;
    padding: 30px 20px 10px;
    background: #f00;
    border-radius: 10px;
    font-weight: 800;
    font-size: 18px;
    letter-spacing: 1px;
    text-transform: uppercase;
    box-shadow: 0 15px 35px rgba(0,0,0,0.2);
    z-index: 1;
    pointer-events: none;
    transition: bottom 0.5s, z-index 0s, transform 0.5s, padding 0.5s;
    transition-delay: 0.5s,0.5s,0s,0.5s;
    color: #fff;
}
.card:hover .text{
    transition-delay: 0s,0.5s,0.5s,0s;
    bottom: -70px;
    z-index: 11;
    transform: translateX(-50%) translateY(-50px);
    padding: 10px 20px 10px;
}
.card:nth-child(1) .text{
    background: #ff0461;
}
.card:nth-child(2) .text{
    background: #2bd2ff;
}
.card:nth-child(3) .text{
    background: #18d539;
}
.button{
    position: absolute;
    bottom: -110px;
    left: 35%;
    width: 60%;
    z-index: 10;
    text-align: center;
    padding: 30px ,20px, 10px;
    background: #f00;
    border-radius: 10px;
    font-weight: 800;
    font-size: 18px;
    letter-spacing: 1px;
    text-transform: uppercase;
    box-shadow: 0 15px 35px rgba(0,0,0,0.2);
    z-index: 1;
    color: #fff;
}
.card:nth-child(1) .button{
    border: #ff0461;
    background: #ff0461;
}
.card:nth-child(2) .button{
    border: #2bd2ff;
    background: #2bd2ff;
}
.card:nth-child(3) .button{
    border: #18d539;
    background: #18d539;
}
svg{
    position: relative;
    width: 150px;
    height: 150px;
}
svg circle{
    width: 100%;
    height: 100%;
    fill: none;
    stroke-width: 10;
    stroke: rgba(255,255,255,0.05);
    transform: translate(5px,5px);
    stroke-linecap: round;
}
svg circle:nth-child(2){
    stroke: #fff;
    stroke-dasharray: 440px;
    stroke-dashoffset: 440px;
}
.card:nth-child(1) svg circle:nth-child(2){
    stroke-dashoffset: calc(440px - (440px*20)/100);
}
.card:nth-child(2) svg circle:nth-child(2){
    stroke-dashoffset: calc(440px - (440px*85)/100);
}
.card:nth-child(3) svg circle:nth-child(2){
    stroke-dashoffset: calc(440px - (440px*65)/100);
} 
</style>
<body>
    <section>
        <div class="container">
            <div class="card">
                <div class="box">
                    <div>
                        <div class="percent">
                            <svg>
                                <circle cx="70" cy="70" r="70"></circle>
                                <circle cx="70" cy="70" r="70"></circle>
                            </svg>
                            <div class="number">
                                <h2><var id="TempValue">20</var><span>C</span></h2>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="text">TEMP</div>
                <div>
                    <button type="button" class="button" onclick="fan_btn()" > <span>FAN:</span><var id="F_status"></var></button>
                </div>
            </div>
            <div class="card">
                <div class="box">
                    <div>
                        <div class="percent">
                            <svg>
                                <circle cx="70" cy="70" r="70"></circle>
                                <circle cx="70" cy="70" r="70"></circle>
                            </svg>
                            <div class="number">
                                <h2><var id="WatValue">80</var><span>%</span></h2>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="text">WATER</div>
                <div>
                    <button type="button" class="button" onclick="pump_btn()"><span> Pump:</span><var id="P_status"></var></button>
                </div>
            </div>
            <div class="card">
                <div class="box">
                    <div>
                        <div class="percent">
                            <svg id="circle">
                                <circle cx="70" cy="70" r="70"></circle>
                                <circle cx="70" cy="70" r="70"></circle>
                            </svg>
                            <div class="number">
                                <h2><var id="PwrValue">65</var><span>%</span></h2>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="text">Power</div>
                <div>
                    <button type="button" class="button" onclick="light_btn()"><span > Lights:</span><var id="l_status"></var></button>
                </div>
            </div>
        </div>
    </section>
</body>
<script>
       setInterval(function()
    {
      getTemp();
      getTanLev();
      getPwr();
     
    },2000);
    //-------------------------------------------------------


    var POTvalRequest = new XMLHttpRequest();
    var message;

    function getTemp()
    {
      var message;
      var value;
      POTvalRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          message = this.responseText;
          value = (int(message)/4095 * 100);
          document.getElementById("TempValue").innerHTML = value ;
          
        }
      };
      POTvalRequest.open("GET", "readPOT", true);
      POTvalRequest.send();
      return;
    }

    function getTanLev(){
      POTvalRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          document.getElementById("WatValue").innerHTML = this.responseText;
        }
      }
      POTvalRequest.open("GET","water",false);
      POTvalRequest.send();
      return;
    }

    function getPwr(){
      POTvalRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          document.getElementById("PwrValue").innerHTML = this.responseText;
          let reading = this.responseText;
          const circle = document.querySelector(".percent")
          circle.style.strokeDashoffset = reading;
        }
      }
      POTvalRequest.open("GET","pwr",true);
      POTvalRequest.send();
    }
    //-------------------------------------------------------

    function light_btn()
    {
        POTvalRequest.onreadystatechange = function(){
            if(this.readyState == 4 && this.status == 200){
                document.getElementById("l_status").innerHTML=
                this.responseText;
  
            }
        };
        POTvalRequest.open("GET", "light", false);
        POTvalRequest.send();
        return;
    }
    function pump_btn()
    {
        POTvalRequest.onreadystatechange = function(){
            if(this.readyState == 4 && this.status == 200){
                document.getElementById("P_status").innerHTML=
                this.responseText;
  
            }
        };
        POTvalRequest.open("GET", "pump", false);
        POTvalRequest.send();
        return;
    }
    function fan_btn()
    {
        POTvalRequest.onreadystatechange = function(){
            if(this.readyState == 4 && this.status == 200){
                document.getElementById("F_status").innerHTML=
                this.responseText;
  
            }
        };
        POTvalRequest.open("GET", "fan", false);
        POTvalRequest.send();
        return;
    }
</script>
</html>
)***";
