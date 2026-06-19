function Main (input) {
  var splittedInputByLine = input.split(/\n/);
  var summerElements = splittedInputByLine[0].split(" ");
  var summerHolidays = summerElements[0];
  var homework = summerElements[1];
  
  var studyDaysArray = splittedInputByLine[1].split(" ");
  var studyDays = studyDaysArray.map(Number);
      
  if(summerHolidays < homework) {
    console.log('-1');
  } else {
    var totalStudyDays = 0;
    for ( var i = 0; i < homework; i ++){
      totalStudyDays += studyDays[i];
    }
    console.log(summerHolidays - totalStudyDays);
    
  }
  
	
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
