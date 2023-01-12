function createListFromCSV(){
    return new Promise((resolve, reject) => {
        const wholeCSV = [];
        fs.createReadStream('../csv/countrycodes.csv')
            .on('error' , reject)
            .pipe(csvParser())
            .on('data', (row) => {
                wholeCSV.push(row);
             })
            .on('end', ()=> {
                resolve(wholeCSV);
            });
    })
}