library(shiny)
library(ggplot2)

wine_data <- read.csv("WineQT.csv")

ui <- fluidPage(
  titlePanel("Line Plot"),
  mainPanel(
    plotOutput("lineplot")
  )
)

server <- function(input, output) {
  output$lineplot <- renderPlot({
    ggplot(wine_data, aes(x = fixed.acidity, y = pH)) +
      geom_line() +
      labs(title = "Line plot of Fixed Acidity vs pH", x = "Fixed Acidity", y = "pH")
  })
}

shinyApp(ui = ui, server = server)
